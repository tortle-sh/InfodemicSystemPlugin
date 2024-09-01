// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IDSNode.h"
#include "UObject/Object.h"
#include "IDSNode_Actor.generated.h"

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDSNode_Actor : public UIDSNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<AActor> Actor;
};