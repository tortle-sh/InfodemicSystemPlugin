// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "nodes/IDSNode.h"
#include "UObject/Object.h"
#include "IDSRelation.generated.h"

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDSRelation : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	FText Title;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UIDSNode>> StartNodeTypes;
	
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UIDSNode>> EndNodeTypes;

public:
	FText GetTitle() const
	{
		return Title;
	}
};
