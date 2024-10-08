// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "nodes/IDS_Node.h"
#include "UObject/Object.h"
#include "IDS_Relation.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class INFODEMICCORE_API UIDS_Relation : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	FText Title;

	UPROPERTY(EditAnywhere)
	FGameplayTagContainer StartNodeTypes;

	UPROPERTY(EditAnywhere)
	FGameplayTagContainer EndNodeTypes;

public:
	[[nodiscard]] FGameplayTagContainer GetStartNodeTypes() const
	{
		return StartNodeTypes;
	}

	[[nodiscard]] FGameplayTagContainer GetEndNodeTypes() const
	{
		return EndNodeTypes;
	}

	[[nodiscard]] FText GetTitle() const
	{
		return Title;
	}
};
