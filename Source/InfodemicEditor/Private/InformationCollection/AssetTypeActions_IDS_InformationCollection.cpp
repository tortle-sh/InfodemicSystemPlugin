// Fill out your copyright notice in the Description page of Project Settings.


#include "InformationCollection/AssetTypeActions_IDS_InformationCollection.h"

#include "base/IDS_InformationCollection.h"

FAssetTypeActions_IDS_InformationCollection::FAssetTypeActions_IDS_InformationCollection(EAssetTypeCategories::Type InfodemicCategory): FIDSAssetTypeActions_Base(InfodemicCategory)
{
}

UClass* FAssetTypeActions_IDS_InformationCollection::GetSupportedClass() const
{
	return UIDS_InformationCollection::StaticClass();
}

FText FAssetTypeActions_IDS_InformationCollection::GetName() const
{
	return INVTEXT("IDS Information Collection");
}

FColor FAssetTypeActions_IDS_InformationCollection::GetTypeColor() const
{
	return FColor::Purple;
}
