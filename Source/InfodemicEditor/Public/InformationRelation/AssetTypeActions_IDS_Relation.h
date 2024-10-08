// Copyright 2024 tortle-sh. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "common/IDSAssetTypeActions_Base.h"

class INFODEMICEDITOR_API FAssetTypeActions_IDS_Relation : public FIDSAssetTypeActions_Base
{
public:
	explicit FAssetTypeActions_IDS_Relation(EAssetTypeCategories::Type MyCategory);
	
	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual FColor GetTypeColor() const override;
};
