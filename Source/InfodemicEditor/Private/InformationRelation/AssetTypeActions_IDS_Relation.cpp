// Copyright 2024 tortle-sh. All Rights Reserved


#include "InformationRelation/AssetTypeActions_IDS_Relation.h"

#include "base/IDS_Relation.h"

FAssetTypeActions_IDS_Relation::FAssetTypeActions_IDS_Relation(
	EAssetTypeCategories::Type MyCategory): FIDSAssetTypeActions_Base(MyCategory)
{
}

FText FAssetTypeActions_IDS_Relation::GetName() const
{
	return INVTEXT("Information Relation");
}

UClass* FAssetTypeActions_IDS_Relation::GetSupportedClass() const
{
	return UIDS_Relation::StaticClass();
}

FColor FAssetTypeActions_IDS_Relation::GetTypeColor() const
{
	return FColor::Red;
}
