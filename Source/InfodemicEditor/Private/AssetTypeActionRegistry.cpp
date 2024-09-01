#include "AssetTypeActionRegistry.h"

TMap<FString, FActionsArray> FAssetTypeActionRegistry::Actions = {};

void FAssetTypeActionRegistry::RegisterActions(const FString &ActionNamespace, FActionsArray NewActions)
{
	FActionsArray* NamespaceActions = Actions.Find(ActionNamespace);
	if (NamespaceActions == nullptr)
	{
		Actions.Add(ActionNamespace, {});
		NamespaceActions = Actions.Find(ActionNamespace);
	}

	for (auto Action : NewActions)
	{
		FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(Action.ToSharedRef());
		NamespaceActions->Add(Action);
	}
}

void FAssetTypeActionRegistry::UnregisterAllActions()
{
	for (auto ActionPair : Actions)
	{
		UnregisterActions(ActionPair.Key);
	}
}

void FAssetTypeActionRegistry::UnregisterActions(FString ActionNamespace)
{
	if (!FModuleManager::Get().IsModuleLoaded("AssetTools")) return;

	FActionsArray* NamespaceActions = Actions.Find(ActionNamespace);

	for (auto Action : *NamespaceActions)
	{
		FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(Action.ToSharedRef());
	}
}
