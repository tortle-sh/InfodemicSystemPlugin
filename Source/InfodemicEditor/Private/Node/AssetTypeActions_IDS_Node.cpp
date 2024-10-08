// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/AssetTypeActions_IDS_Node.h"

#include "base/nodes/IDS_Node.h"

FAssetTypeActions_IDS_Node::FAssetTypeActions_IDS_Node(EAssetTypeCategories::Type MyCategory): FIDSAssetTypeActions_Base(MyCategory)
{
}

UClass* FAssetTypeActions_IDS_Node::GetSupportedClass() const
{
	return UIDS_Node::StaticClass();
}

FText FAssetTypeActions_IDS_Node::GetName() const
{
	return INVTEXT("IDS Node");
}

FColor FAssetTypeActions_IDS_Node::GetTypeColor() const
{
	return FColor::Green;
}

