// Copyright 2024 tortle-sh. All Rights Reserved

#include "InfodemicAssetManager.h"

#include "base/IDSInformationBundle.h"


void UInfodemicAssetManager::LoadInfodemicAssets()
{
	LoadPrimaryAssetsWithType(InformationBundleType);
	UE_LOG(LogTemp, Display, TEXT("Infodemic initialized"));
	UnloadPrimaryAssetsWithType(InformationBundleType);
}

void UInfodemicAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	ScanPathsForPrimaryAssets(InformationBundleType, {"/Game/SlimyAdventures/GraphSchema/InformationBundles"}, UIDSInformationBundle::StaticClass(), false);
}

void UInfodemicAssetManager::OnAssetRegistryFilesLoaded()
{
	Super::OnAssetRegistryFilesLoaded();
	UE_LOG(LogTemp, Display, TEXT("OnAssetRegistryFilesLoaded"));
	LoadInfodemicAssets();
}
