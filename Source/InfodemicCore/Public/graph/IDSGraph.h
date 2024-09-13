// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagObserver.h"
#include "GenericGraph.h"
#include "base/IDSInformationBundle.h"
#include "IDSGraph.generated.h"

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDSGraph : public UGenericGraph 
{
	GENERATED_BODY()

	UIDSGraph();

	UPROPERTY(EditAnywhere, Category=Information)
	TArray<UIDSInformationBundle*> UniqueInformationCollection;

	UPROPERTY()
	TArray<UIDSInformationBundle*> InheritedInformationCollection;
	
	UPROPERTY(EditAnywhere, Category=Information)
	FGameplayTagObserver InheritedInformation = {this};

	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;

	UPROPERTY()
	TArray<UIDSInformationBundle*> CombinedInformationCollection;

	UFUNCTION()
	void UpdateCombinedInformationCollection();

	UFUNCTION()
	void OnInheritedInformationUpdated();
public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;	
};
