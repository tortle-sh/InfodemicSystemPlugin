// Copyright 2024 tortle-sh. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "UObject/Object.h"
#include "InfodemicAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class INFODEMICCORE_API UInfodemicAssetManager : public UAssetManager
{
	GENERATED_BODY()

protected:
	virtual void OnAssetRegistryFilesLoaded() override;
	
public:
	void LoadInfodemicAssets();
	virtual void StartInitialLoading() override;
};