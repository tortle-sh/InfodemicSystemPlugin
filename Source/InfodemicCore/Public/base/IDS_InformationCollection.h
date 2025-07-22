// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTagObserver.h"
#include "GenericGraph.h"
#include "OnDeleteAsset.h"
#include "base/IDS_InformationBundle.h"
#include "nodes/IDS_Node_Character.h"
#include "IDS_InformationCollection.generated.h"

class UIDS_InformationBundle;

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDS_InformationCollection : public UGenericGraph, public IOnDeleteAsset
{
	GENERATED_BODY()

	UIDS_InformationCollection();

	UPROPERTY(EditAnywhere, Category=Information)
	FAssetTagObserver InheritedInformationObserver = {Parents, UIDS_InformationBundle::StaticClass()};

	UPROPERTY(EditAnywhere, Category=Information)
	TSet<TSoftObjectPtr<UIDS_InformationBundle>> UniqueInformationCollection;

	UPROPERTY(VisibleAnywhere)
	TSet<TSoftObjectPtr<UIDS_InformationBundle>> CombinedInformationCollection;
	
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;

	virtual void OnDeleteAsset_Implementation() override;

	UFUNCTION()
	void UpdateInheritedInformation(
		EBroadcastType BroadcastType,
		const TSoftObjectPtr<UObject>& ChangedObject, const FGameplayTag& UpdatedGameplayTag, uint32 NodeHash);

	UFUNCTION()
	void OnObservedObjectsChanged();

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category=Information)
	TSoftObjectPtr<UIDS_Node_Character> SelfCharacter;

	[[nodiscard]] const TSoftObjectPtr<UIDS_Node_Character>& GetSelfCharacter() const
	{
		return SelfCharacter;
	}

	UFUNCTION(BlueprintCallable)
	FText GetOwnCharacterName() const;

	UFUNCTION()
	void UpdateCombinedInformationCollection();

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
	
	UFUNCTION(CallInEditor, BlueprintCallable, DisplayName="Load Into DB")
	void LoadIntoDb();

	[[nodiscard]] const TSet<TSoftObjectPtr<UIDS_InformationBundle>>& GetCombinedInformationCollection() const
	{
		return CombinedInformationCollection;
	}
};
