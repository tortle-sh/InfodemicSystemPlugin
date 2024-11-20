// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "nodes/IDS_Node.h"
#include "IDS_Relation.h"
#include "UObject/Object.h"
#include "IDS_Information.generated.h"

class UIDS_InformationBundle;
/**
 * 
 */
USTRUCT(BlueprintType)
struct INFODEMICCORE_API FIDS_Information 
{
	GENERATED_BODY()
	TSoftObjectPtr<UIDS_InformationBundle> Bundle;

	UPROPERTY(EditAnywhere)
 	UIDS_Node* StartNode;

	UPROPERTY(EditAnywhere)
	UIDS_Relation* Relation;

	UPROPERTY(EditAnywhere)
	UIDS_Node* EndNode;

	FGuid InformationId = FGuid::NewGuid();

	bool operator==(const FIDS_Information& Other) const
	{
		return Equals(Other);
	}

	bool Equals(const FIDS_Information &Other) const
	{
		return InformationId == Other.InformationId;
	}
};

inline uint32 GetTypeHash(const FIDS_Information &Information)
{
	const FGuid Id = Information.InformationId;
	const uint32 Hash = FCrc::MemCrc32(&Id, sizeof(FGuid));
	return Hash;
}
