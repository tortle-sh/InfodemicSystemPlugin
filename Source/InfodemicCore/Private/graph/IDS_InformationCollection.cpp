#include "base/IDS_InformationCollection.h"

#include "InfodemicConstants.h"
#include "InfodemicCore.h"
#include "db/InfodemicDbSubsystem.h"
#include "graph/IDS_GraphEdge.h"
#include "graph/IDS_GraphNode.h"


UIDS_InformationCollection::UIDS_InformationCollection()
{
	NodeType = UIDS_GraphNode::StaticClass();
	EdgeType = UIDS_GraphEdge::StaticClass();

	UIDS_GraphNode *Node = NewObject<UIDS_GraphNode>();
	Node->SetNodeTitle(FText::FromString("test"));
	AllNodes.Add(Node);
}

void UIDS_InformationCollection::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);

	if (PropertyAboutToChange->GetFName() == GET_MEMBER_NAME_CHECKED(FAssetTagObserver, TagContainer))
	{
		InheritedInformationObserver.PreEditChange();
	}
}

void UIDS_InformationCollection::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);

	this->InheritedInformationObserver.InitializeObserver();
	// todo: integrate InheritedInformationObserver.Validate()
	
	this->InheritedInformationObserver.OnSubscribedNodesUpdated.BindDynamic(this, &UIDS_InformationCollection::UpdateInheritedInformation);
	this->InheritedInformationObserver.OnObservedObjectsChanged.BindDynamic(this, &UIDS_InformationCollection::OnObservedObjectsChanged);
}

void UIDS_InformationCollection::OnDeleteAsset_Implementation()
{
	this->InheritedInformationObserver.DeinitializeObserver();
}

FText UIDS_InformationCollection::GetOwnCharacterName() const
{
	if (!SelfCharacter.IsValid())
	{
		return FText::FromString(TEXT(""));
	}

	return SelfCharacter->GetName();
}

void UIDS_InformationCollection::UpdateCombinedInformationCollection()
{
	CombinedInformationCollection.Empty();
	CombinedInformationCollection.Append(InheritedInformationObserver.GetObservedObjects<UIDS_InformationBundle>());
	CombinedInformationCollection.Append(UniqueInformationCollection);
}

void UIDS_InformationCollection::UpdateInheritedInformation(
	const EBroadcastType BroadcastType,
	const TSoftObjectPtr<UObject>& ChangedObject,
	const FGameplayTag &UpdatedGameplayTag,
	const uint32 NodeHash
	)
{
	this->InheritedInformationObserver.OnCallbackUpdateObservedObjects(BroadcastType, ChangedObject, UpdatedGameplayTag, NodeHash);
}

void UIDS_InformationCollection::OnObservedObjectsChanged()
{
	UpdateCombinedInformationCollection();
}

void UIDS_InformationCollection::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(
		UIDS_InformationCollection, InheritedInformationObserver))
	{
		InheritedInformationObserver.PostEditChangeProperty(PropertyChangedEvent);
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

void UIDS_InformationCollection::LoadIntoDb()
{
	UE_LOG(InfodemicCore, Display, TEXT("load db called"));
	
	const UInfodemicDbSubsystem* DbSubsystem = GEngine->GetEngineSubsystem<UInfodemicDbSubsystem>();
	check(DbSubsystem != nullptr);
	
	DbSubsystem->PersistCollection(this);
}
