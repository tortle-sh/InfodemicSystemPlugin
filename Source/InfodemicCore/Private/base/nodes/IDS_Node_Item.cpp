// Copyright 2024 tortle-sh. All Rights Reserved


#include "base/nodes/IDS_Node_Item.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ids_Node_Actor_Item_Tag, "Node.Actor.Item", "Default Tag for Items");

UIDS_Node_Item::UIDS_Node_Item()
{
	SetDefaultNodeType(Ids_Node_Actor_Item_Tag);
}
