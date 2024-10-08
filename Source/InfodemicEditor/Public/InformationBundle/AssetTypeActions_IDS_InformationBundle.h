// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "common/IDSAssetTypeActions_Base.h"

/**
 * 
 */
class INFODEMICEDITOR_API FAssetTypeActions_IDS_InformationBundle : public FIDSAssetTypeActions_Base
{
public:
	explicit FAssetTypeActions_IDS_InformationBundle(EAssetTypeCategories::Type MyCategory);

	virtual UClass* GetSupportedClass() const override;
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
};
