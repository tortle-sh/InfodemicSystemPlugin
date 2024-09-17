// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagObserver.h"
#include "GenericGraph.h"
#include "OnDeleteAsset.h"
#include "base/IDSInformationBundle.h"
#include "IDSGraph.generated.h"

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDSGraph : public UGenericGraph, public IOnDeleteAsset
{
	GENERATED_BODY()

	UIDSGraph();
	
	UPROPERTY(EditAnywhere, Category=Information)
	FGameplayTagObserver InheritedInformation = {this};

	UPROPERTY(EditAnywhere, Category=Information)
	TSet<TSoftObjectPtr<UIDSInformationBundle>> UniqueInformationCollection;

	UPROPERTY(VisibleAnywhere, Category=Information)
	TSet<TSoftObjectPtr<UIDSInformationBundle>> InheritedInformationCollection;
	
	UPROPERTY()
	TSet<TSoftObjectPtr<UIDSInformationBundle>> CombinedInformationCollection;

	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;

	virtual void OnDeleteAsset_Implementation() override;

	UFUNCTION()
	void UpdateCombinedInformationCollection();

	UFUNCTION()
	void UpdateInheritedInformation();
public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;	
};
