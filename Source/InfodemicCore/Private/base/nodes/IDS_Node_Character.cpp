#include "base/nodes/IDS_Node_Character.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ids_Node_Actor_Character_Tag, "Node.Actor.Character", "Infodemic Tag for Characters")

UIDS_Node_Character::UIDS_Node_Character()
{
	SetDefaultNodeType(Ids_Node_Actor_Character_Tag);
}

FText UIDS_Node_Character::GetNodeTitle()
{
	return Name;
}

const FText& UIDS_Node_Character::GetName() const
{
	return Name;
}
