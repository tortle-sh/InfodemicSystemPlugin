#include "base/IDSGraph.h"

#include "GameplayTagsManager.h"
#include "graph/IDSGraphEdge.h"
#include "graph/IDSGraphNode.h"


UIDSGraph::UIDSGraph()
{
	NodeType = UIDSGraphNode::StaticClass();
	EdgeType = UIDSGraphEdge::StaticClass();
}

void UIDSGraph::UpdateCombinedInformationCollection()
{
	CombinedInformationCollection.Empty();
	CombinedInformationCollection.Append(InheritedInformationCollection);
	CombinedInformationCollection.Append(UniqueInformationCollection);
}

void UIDSGraph::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if(PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDSGraph, InheritedInformation))
	{
		UGameplayTagsManager &TagManager = UGameplayTagsManager::Get();
	}

	if(PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDSGraph, InheritedInformationCollection) ||
		PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDSGraph, UniqueInformationCollection))
	{
		UpdateCombinedInformationCollection();
	}
}
