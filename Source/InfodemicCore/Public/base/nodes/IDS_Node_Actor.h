// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IDS_Node.h"
#include "NativeGameplayTags.h"
#include "UObject/Object.h"
#include "IDS_Node_Actor.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ids_Node_Actor_Tag)

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDS_Node_Actor : public UIDS_Node
{
	GENERATED_BODY()

protected:
	UIDS_Node_Actor();
	
	UPROPERTY(EditAnywhere, Category=Properties)
	TSoftObjectPtr<AActor> Actor;
};