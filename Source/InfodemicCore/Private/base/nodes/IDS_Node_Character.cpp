#include "base/nodes/IDS_Node_Character.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ids_Type_Node_Actor_Character, "Ids.Type.Node.Actor.Character", "Infodemic Tag for Characters")

UIDS_Node_Character::UIDS_Node_Character()
{
	SetDefaultNodeType(Ids_Type_Node_Actor_Character);
}

FText UIDS_Node_Character::GetNodeTitle()
{
	return CharacterName;
}
