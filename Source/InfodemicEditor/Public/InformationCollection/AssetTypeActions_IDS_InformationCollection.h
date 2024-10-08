// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "common/IDSAssetTypeActions_Base.h"

/**
 * 
 */
class INFODEMICEDITOR_API FAssetTypeActions_IDS_InformationCollection : public FIDSAssetTypeActions_Base
{
public:
	explicit FAssetTypeActions_IDS_InformationCollection(EAssetTypeCategories::Type MyCategory);

private:
	virtual UClass* GetSupportedClass() const override;
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
};
