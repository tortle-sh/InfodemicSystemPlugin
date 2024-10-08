#include "graph/IDS_GraphNode.h"
#include "base/IDS_InformationCollection.h"

UIDS_GraphNode::UIDS_GraphNode()
{
	CompatibleGraphType = UIDS_InformationCollection::StaticClass();
}

void UIDS_GraphNode::SetNodeTitleToIdsNodeTitle()
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

void UIDS_GraphNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if(PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDS_GraphNode, IdsNode))
	{
		SetNodeTitleToIdsNodeTitle();
	}
}
