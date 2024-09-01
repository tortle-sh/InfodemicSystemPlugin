// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "nodes/IDSNode.h"
#include "IDSRelation.h"
#include "UObject/Object.h"
#include "IDSInformation.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct INFODEMICCORE_API FUIDSInformation 
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
 	TSoftObjectPtr<UIDSNode> StartNode;

	UPROPERTY(VisibleAnywhere)
	TSoftObjectPtr<UIDSRelation> Relation;

	UPROPERTY(VisibleAnywhere)
	TSoftObjectPtr<UIDSNode> EndNode;
};
