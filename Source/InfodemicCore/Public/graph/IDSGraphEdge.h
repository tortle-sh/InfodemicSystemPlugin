// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericGraphEdge.h"
#include "base/IDSRelation.h"
#include "UObject/Object.h"
#include "IDSGraphEdge.generated.h"

class UIDSRelation;

UCLASS()
class INFODEMICCORE_API UIDSGraphEdge : public UGenericGraphEdge
{
	GENERATED_BODY()

protected:
	UIDSGraphEdge();

	void SetNodeTitleToIdsRelationTitle();

public:
	UPROPERTY(EditAnywhere)
	TWeakObjectPtr<UIDSRelation> IdsRelation;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
