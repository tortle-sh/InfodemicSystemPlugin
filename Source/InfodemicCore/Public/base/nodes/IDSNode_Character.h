// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IDSNode_Actor.h"
#include "UObject/Object.h"
#include "IDSNode_Character.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class INFODEMICCORE_API UIDSNode_Character : public UIDSNode_Actor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	FText CharacterName;

	virtual FText GetNodeTitle() override;
};
