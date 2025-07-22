// Copyright 2024 tortle-sh. All Rights Reserved

#include "InfodemicAssetManager.h"
#include "OnDeleteAsset.h"
#include "InfodemicConstants.h"
#include "InfodemicCore.h"
#include "db/InfodemicDbSubsystem.h"


void UInfodemicAssetManager::LoadInfodemicAssets()
{
	LoadPrimaryAssetsWithType(InformationBundleType);
	UnloadPrimaryAssetsWithType(InformationBundleType);
	
	LoadPrimaryAssetsWithType(InformationCollectionType);
	UnloadPrimaryAssetsWithType(InformationCollectionType);
}

void UInfodemicAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	UE_LOG(InfodemicCore, Display, TEXT("%s initial load"), *GetName());
}

void UInfodemicAssetManager::OnAssetRemoved(const FAssetData& Data)
{
	if(Data.GetAsset() == nullptr)
	{
		return;
	}
	
	if(Data.GetAsset()->Implements<UOnDeleteAsset>())
	{
		IOnDeleteAsset::Execute_OnDeleteAsset(Data.GetAsset());
	}

	Super::OnAssetRemoved(Data);
}

void UInfodemicAssetManager::OnAssetRegistryFilesLoaded()
{
	Super::OnAssetRegistryFilesLoaded();
	UE_LOG(InfodemicCore, Display, TEXT("OnAssetRegistryFilesLoaded"));
	LoadInfodemicAssets();
}
