// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "UObject/Object.h"
#include "IDS_Node.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ids_Node_Tag);

UCLASS(BlueprintType, EditInlineNew)
class INFODEMICCORE_API UIDS_Node : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	FGameplayTagContainer NodeTypes;

	UPROPERTY(VisibleAnywhere, Category=Property)
	FString NodeId = FGuid::NewGuid().ToString();

	UIDS_Node();
	void SetDefaultNodeType(const FGameplayTag &Tag);

public:
	[[nodiscard]] FGameplayTagContainer GetNodeTypes() const
	{
		return NodeTypes;
	}

	virtual FText GetNodeTitle()
	{
		return FText::FromString("Generic Ids Node");
	}
};
