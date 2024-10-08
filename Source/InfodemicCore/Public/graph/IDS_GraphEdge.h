// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericGraphEdge.h"
#include "base/IDS_Relation.h"
#include "UObject/Object.h"
#include "IDS_GraphEdge.generated.h"

class UIDS_Relation;

UCLASS()
class INFODEMICCORE_API UIDS_GraphEdge : public UGenericGraphEdge
{
	GENERATED_BODY()

protected:
	UIDS_GraphEdge();

	void SetNodeTitleToIdsRelationTitle();

public:
	UPROPERTY(EditAnywhere)
	TWeakObjectPtr<UIDS_Relation> IdsRelation;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
