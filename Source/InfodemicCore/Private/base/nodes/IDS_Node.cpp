#include "base/nodes/IDS_Node.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ids_Node_Tag, "Node", "Infodemic generic node tag");

UIDS_Node::UIDS_Node()
{
	SetDefaultNodeType(Ids_Node_Tag);
}

void UIDS_Node::SetDefaultNodeType(const FGameplayTag& Tag)
{
	NodeTypes.Reset();
	NodeTypes.AddTag(Tag);
}
