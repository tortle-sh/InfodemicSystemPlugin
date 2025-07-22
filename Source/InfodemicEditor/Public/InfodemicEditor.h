// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(InfodemicEditor, Display, All);

class FAssetTypeActions_IDS_InformationBundle;
class FToolBarBuilder;
class FMenuBuilder;

class FInfodemicEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command (by default it will bring up plugin window) */
	void PluginButtonClicked();
	
private:

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);
	TSharedPtr<class FUICommandList> PluginCommands;
	EAssetTypeCategories::Type InfodemicEditorCategoryBit;
	
	void RegisterMenus();
};
