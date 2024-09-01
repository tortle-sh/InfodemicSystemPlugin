// Fill out your copyright notice in the Description page of Project Settings.


#include "Graph/IDSAssetTypeActions_IDSGraph.h"

#include "base/IDSGraph.h"

FIDSAssetTypeActions_IDSGraph::FIDSAssetTypeActions_IDSGraph(EAssetTypeCategories::Type MyCategory): FIDSAssetTypeActions_Base(MyCategory)
{
}

UClass* FIDSAssetTypeActions_IDSGraph::GetSupportedClass() const
{
	return UIDSGraph::StaticClass();
}

FText FIDSAssetTypeActions_IDSGraph::GetName() const
{
	return INVTEXT("IDS Graph");
}

FColor FIDSAssetTypeActions_IDSGraph::GetTypeColor() const
{
	return FColor::Purple;
}
