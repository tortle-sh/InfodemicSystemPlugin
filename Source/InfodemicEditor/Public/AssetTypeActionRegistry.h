#pragma once

#include "AssetTypeActions_Base.h"

class FAssetTypeActions_Base;

typedef TArray<TSharedPtr<FAssetTypeActions_Base>> FActionsArray;
class FAssetTypeActionRegistry
{
private:
	static TMap<FString, FActionsArray> Actions;
	
public:
	static void RegisterActions(const FString &ActionNamespace, FActionsArray);
	static void UnregisterAllActions();
	static void UnregisterActions(FString ActionNamespace);
	
};
