// Copyright 2024 tortle-sh. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "IDS_Node_Actor.h"
#include "UObject/Object.h"
#include "IDS_Node_Item.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ids_Node_Actor_Item_Tag);

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDS_Node_Item : public UIDS_Node_Actor
{
	GENERATED_BODY()

protected:
	UIDS_Node_Item();
};
