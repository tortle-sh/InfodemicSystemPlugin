// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IDS_Node_Actor.h"
#include "NativeGameplayTags.h"
#include "UObject/Object.h"
#include "IDS_Node_Character.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ids_Node_Actor_Character_Tag);

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDS_Node_Character : public UIDS_Node_Actor
{
	GENERATED_BODY()

	UIDS_Node_Character();

protected:
	UPROPERTY(EditDefaultsOnly, Category=Property)
	FText Name;

	virtual FText GetNodeTitle() override;
	
public:
	UFUNCTION(Blueprintable)
	[[nodiscard]] const FText& GetName() const;
};
