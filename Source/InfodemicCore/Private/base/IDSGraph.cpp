#include "base/IDSGraph.h"

#include "GameplayTagsManager.h"
#include "graph/IDSGraphEdge.h"
#include "graph/IDSGraphNode.h"


UIDSGraph::UIDSGraph()
{
	NodeType = UIDSGraphNode::StaticClass();
	EdgeType = UIDSGraphEdge::StaticClass();
}

void UIDSGraph::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);

	if(PropertyAboutToChange->GetFName() == GET_MEMBER_NAME_CHECKED(FGameplayTagObserver, TagContainer))
	{
		InheritedInformation.PreEditChange();
	}
}

void UIDSGraph::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);

	this->InheritedInformation.Callback.BindDynamic(this, &UIDSGraph::OnInheritedInformationUpdated);
}

void UIDSGraph::UpdateCombinedInformationCollection()
{
	CombinedInformationCollection.Empty();
	CombinedInformationCollection.Append(InheritedInformationCollection);
	CombinedInformationCollection.Append(UniqueInformationCollection);
}

void UIDSGraph::OnInheritedInformationUpdated()
{
	UE_LOG(LogTemp, Display, TEXT("Inherited Information Updated"));
}

void UIDSGraph::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if(PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDSGraph, InheritedInformation))
	{
		InheritedInformation.PostEditChangeProperty(PropertyChangedEvent);
	}

	if(PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDSGraph, InheritedInformationCollection) ||
		PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDSGraph, UniqueInformationCollection))
	{
		UpdateCombinedInformationCollection();
	}
}
