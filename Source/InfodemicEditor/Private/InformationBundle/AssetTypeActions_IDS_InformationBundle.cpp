// Fill out your copyright notice in the Description page of Project Settings.


#include "InformationBundle/AssetTypeActions_IDS_InformationBundle.h"

#include "base/IDS_InformationBundle.h"

FAssetTypeActions_IDS_InformationBundle::FAssetTypeActions_IDS_InformationBundle(
	EAssetTypeCategories::Type MyCategory): FIDSAssetTypeActions_Base(MyCategory)
{
}

UClass* FAssetTypeActions_IDS_InformationBundle::GetSupportedClass() const
{
	return UIDS_InformationBundle::StaticClass();
}

FText FAssetTypeActions_IDS_InformationBundle::GetName() const
{
	return INVTEXT("Information Bundle");
}

FColor FAssetTypeActions_IDS_InformationBundle::GetTypeColor() const
{
	return FColor::Blue;
}
