#include "base/nodes/IDS_Node_Actor.h"

UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ids_Node_Actor_Tag, "Node.Actor", "Infodemic Type for generic assets");

UIDS_Node_Actor::UIDS_Node_Actor()
{
	SetDefaultNodeType(Ids_Node_Actor_Tag);
}
