// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "IDSNode.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class INFODEMICCORE_API UIDSNode : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	FGameplayTagContainer Tags;

public:
	virtual FText GetNodeTitle()
	{
		return FText::FromString("Generic Ids Node");
	}
};
