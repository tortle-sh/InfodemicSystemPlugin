// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagSubject.h"
#include "IDSInformation.h"
#include "OnDeleteAsset.h"
#include "UObject/Object.h"

#include "IDSInformationBundle.generated.h"

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDSInformationBundle : public UPrimaryDataAsset, public IOnDeleteAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=MetaData)
	FText Title;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=MetaData)
	FText Description;
	
	UPROPERTY(EditAnywhere, Category=Information)
	TArray<FUIDSInformation> Information;

	UPROPERTY(EditAnywhere, Category=Information)
	FGameplayTagSubject InformationCategories = {this, TAG_AND_CHILDREN};

public:
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	virtual void OnDeleteAsset_Implementation() override;
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};

