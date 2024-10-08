// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "nodes/IDS_Node.h"
#include "IDS_Relation.h"
#include "UObject/Object.h"
#include "IDS_Information.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct INFODEMICCORE_API FIDS_Information 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
 	UIDS_Node* StartNode;

	UPROPERTY(EditAnywhere)
	UIDS_Relation* Relation;

	UPROPERTY(EditAnywhere)
	UIDS_Node* EndNode;
};
