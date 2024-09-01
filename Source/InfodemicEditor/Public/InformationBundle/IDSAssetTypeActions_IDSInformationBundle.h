// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "common/IDSAssetTypeActions_Base.h"

/**
 * 
 */
class INFODEMICEDITOR_API FIDSAssetTypeActions_IDSInformationBundle : public FIDSAssetTypeActions_Base
{
public:
	explicit FIDSAssetTypeActions_IDSInformationBundle(EAssetTypeCategories::Type MyCategory);

	virtual UClass* GetSupportedClass() const override;
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
};
