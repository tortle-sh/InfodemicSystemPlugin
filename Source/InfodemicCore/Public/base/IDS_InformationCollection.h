// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTagObserver.h"
#include "GenericGraph.h"
#include "OnDeleteAsset.h"
#include "base/IDS_InformationBundle.h"
#include "IDS_InformationCollection.generated.h"

class UIDS_InformationBundle;

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDS_InformationCollection : public UGenericGraph, public IOnDeleteAsset
{
	GENERATED_BODY()

	UIDS_InformationCollection();

	UPROPERTY(EditAnywhere, Category=Information)
	FAssetTagObserver InheritedInformation = {Parents, UIDS_InformationBundle::StaticClass()};

	UPROPERTY(EditAnywhere, Category=Information)
	TSet<TSoftObjectPtr<UIDS_InformationBundle>> UniqueInformationCollection;

	UPROPERTY(VisibleAnywhere)
	TSet<TSoftObjectPtr<UIDS_InformationBundle>> CombinedInformationCollection;

	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;

	virtual void OnDeleteAsset_Implementation() override;

	UFUNCTION()
	void UpdateCombinedInformationCollection();

	UFUNCTION()
	void UpdateInheritedInformation(EBroadcastType BroadcastType, const TSoftObjectPtr<UObject>& ChangedObject);

	UFUNCTION()
	void OnObservedObjectsChanged();
	
public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;	
};
