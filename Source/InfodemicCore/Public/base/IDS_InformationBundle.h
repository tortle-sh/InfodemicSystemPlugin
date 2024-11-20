// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTagTreeSubsystem.h"

#include "AssetTagSubject.h"
#include "IDS_Information.h"
#include "OnDeleteAsset.h"
#include "UObject/Object.h"

#include "IDS_InformationBundle.generated.h"

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDS_InformationBundle : public UPrimaryDataAsset, public IOnDeleteAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=MetaData)
	FText Title;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=MetaData)
	FText Description;
	
	UPROPERTY(EditAnywhere, Category=Information)
	TSet<FIDS_Information> Information;
	TSet<FIDS_Information> PreChangeInformation;

	UPROPERTY(EditAnywhere, Category=Information)
	FAssetTagSubject InformationCategories = {this, Children};

public:
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	virtual void OnDeleteAsset_Implementation() override;
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	const TSet<FIDS_Information>& GetInformation() const;
};

