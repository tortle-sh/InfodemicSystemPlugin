#include "base/IDS_InformationCollection.h"

#include "InfodemicConstants.h"
#include "graph/IDS_GraphEdge.h"
#include "graph/IDS_GraphNode.h"


UIDS_InformationCollection::UIDS_InformationCollection()
{
	NodeType = UIDS_GraphNode::StaticClass();
	EdgeType = UIDS_GraphEdge::StaticClass();
}

void UIDS_InformationCollection::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);

	if (PropertyAboutToChange->GetFName() == GET_MEMBER_NAME_CHECKED(FAssetTagObserver, TagContainer))
	{
		InheritedInformation.PreEditChange();
	}
}

void UIDS_InformationCollection::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);

	this->InheritedInformation.OnSubscribedNodesUpdated.BindDynamic(this, &UIDS_InformationCollection::UpdateInheritedInformation);
	this->InheritedInformation.OnObservedObjectsChanged.BindDynamic(this, &UIDS_InformationCollection::OnObservedObjectsChanged);
	this->InheritedInformation.InitializeObserver();
}

void UIDS_InformationCollection::OnDeleteAsset_Implementation()
{
	this->InheritedInformation.DeinitializeObserver();
}

void UIDS_InformationCollection::UpdateCombinedInformationCollection()
{
	CombinedInformationCollection.Empty();
	CombinedInformationCollection.Append(InheritedInformation.GetObservedObjects<UIDS_InformationBundle>());
	CombinedInformationCollection.Append(UniqueInformationCollection);
}

void UIDS_InformationCollection::UpdateInheritedInformation(
	const EBroadcastType BroadcastType,
	const TSoftObjectPtr<UObject>& ChangedObject)
{
	this->InheritedInformation.OnCallbackUpdateObservedObjects(BroadcastType, ChangedObject);
}

void UIDS_InformationCollection::OnObservedObjectsChanged()
{
	UpdateCombinedInformationCollection();
}

void UIDS_InformationCollection::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(
		UIDS_InformationCollection, InheritedInformation))
	{
		InheritedInformation.PostEditChangeProperty(PropertyChangedEvent);
	}

	if ( PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(
			UIDS_InformationCollection, UniqueInformationCollection))
	{
		UpdateCombinedInformationCollection();
	}
}

FPrimaryAssetId UIDS_InformationCollection::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(InformationCollectionType, *GetName());
}
