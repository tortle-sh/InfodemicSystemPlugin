// Fill out your copyright notice in the Description page of Project Settings.


#include "InformationBundle/IDSAssetTypeActions_IDSInformationBundle.h"

#include "base/IDSInformationBundle.h"

FIDSAssetTypeActions_IDSInformationBundle::FIDSAssetTypeActions_IDSInformationBundle(
	EAssetTypeCategories::Type MyCategory): FIDSAssetTypeActions_Base(MyCategory)
{
}

UClass* FIDSAssetTypeActions_IDSInformationBundle::GetSupportedClass() const
{
	return UIDSInformationBundle::StaticClass();
}

FText FIDSAssetTypeActions_IDSInformationBundle::GetName() const
{
	return INVTEXT("Information Bundle");
}

FColor FIDSAssetTypeActions_IDSInformationBundle::GetTypeColor() const
{
	return FColor::Blue;
}
