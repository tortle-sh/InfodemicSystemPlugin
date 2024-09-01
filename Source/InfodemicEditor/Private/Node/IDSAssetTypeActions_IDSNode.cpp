// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/IDSAssetTypeActions_IDSNode.h"

#include "base/nodes/IDSNode.h"

FIDSAssetTypeActions_IDSNode::FIDSAssetTypeActions_IDSNode(EAssetTypeCategories::Type MyCategory): FIDSAssetTypeActions_Base(MyCategory)
{
}

UClass* FIDSAssetTypeActions_IDSNode::GetSupportedClass() const
{
	return UIDSNode::StaticClass();
}

FText FIDSAssetTypeActions_IDSNode::GetName() const
{
	return INVTEXT("IDS Node");
}

FColor FIDSAssetTypeActions_IDSNode::GetTypeColor() const
{
	return FColor::Green;
}

