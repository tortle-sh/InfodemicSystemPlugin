#include "graph/IDSGraphNode.h"

#include "base/IDSGraph.h"

UIDSGraphNode::UIDSGraphNode()
{
	CompatibleGraphType = UIDSGraph::StaticClass();
}

void UIDSGraphNode::SetNodeTitleToIdsNodeTitle()
{
	if (IdsNode.IsValid())
	{
		SetNodeTitle(IdsNode->GetNodeTitle());
	}
	else
	{
		SetNodeTitle(FText::FromString("Generic IDS Node"));
	}
}

void UIDSGraphNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if(PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDSGraphNode, IdsNode))
	{
		SetNodeTitleToIdsNodeTitle();
	}
}
