// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "UObject/Object.h"

/**
 * 
 */
class INFODEMICEDITOR_API FIDSAssetTypeActions_Base : public FAssetTypeActions_Base
{
protected:
	EAssetTypeCategories::Type MyCategory;

public:
	explicit FIDSAssetTypeActions_Base(EAssetTypeCategories::Type MyCategory)
		: MyCategory(MyCategory)
	{
	}

private:
	virtual uint32 GetCategories() override;
};
