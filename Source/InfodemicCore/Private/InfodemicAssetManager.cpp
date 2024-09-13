// Copyright 2024 tortle-sh. All Rights Reserved

#include "InfodemicAssetManager.h"

#include "InfodemicConstants.h"
#include "base/IDSInformationBundle.h"


void UInfodemicAssetManager::LoadInfodemicAssets()
{
	LoadPrimaryAssetsWithType(InformationBundleType);
	LoadPrimaryAssetsWithType(GraphType);
	
	UnloadPrimaryAssetsWithType(GraphType);
	UnloadPrimaryAssetsWithType(InformationBundleType);
}

void UInfodemicAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	UE_LOG(LogTemp, Display, TEXT("%s initial load"), *GetName());
}

void UInfodemicAssetManager::OnAssetRegistryFilesLoaded()
{
	Super::OnAssetRegistryFilesLoaded();
	UE_LOG(LogTemp, Display, TEXT("OnAssetRegistryFilesLoaded"));
	LoadInfodemicAssets();
}
