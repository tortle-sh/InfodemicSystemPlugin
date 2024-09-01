// Copyright Epic Games, Inc. All Rights Reserved.

#include "InfodemicEditor.h"

#include "AssetTypeActionRegistry.h"
#include "InfodemicEditorStyle.h"
#include "InfodemicEditorCommands.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "Graph/IDSAssetTypeActions_IDSGraph.h"
#include "InformationBundle/IDSAssetTypeActions_IDSInformationBundle.h"
#include "Node/IDSAssetTypeActions_IDSNode.h"
#include "Tabs/SFullGraphView.h"

static const FName InfodemicEditorTabName("InfodemicEditor");

#define LOCTEXT_NAMESPACE "FInfodemicEditorModule"
#define ACTION_NAMESPACE "InfodemicEditorActions"

void FInfodemicEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FInfodemicEditorStyle::Initialize();
	FInfodemicEditorStyle::ReloadTextures();

	FInfodemicEditorCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FInfodemicEditorCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FInfodemicEditorModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(
		FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FInfodemicEditorModule::RegisterMenus));

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(InfodemicEditorTabName,
	                                                  FOnSpawnTab::CreateRaw( this, 
	                                                  &FInfodemicEditorModule::OnSpawnPluginTab))
	                        .SetDisplayName(LOCTEXT("FInfodemicEditorTabTitle", "InfodemicEditor"))
	                        .SetMenuType(ETabSpawnerMenuType::Hidden);
	                        
	IAssetTools &AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	InfodemicEditorCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("InfodemicSystem")), LOCTEXT("InfodemicCatergory", "Infodemic System"));

	FAssetTypeActionRegistry::RegisterActions(ACTION_NAMESPACE,{
		MakeShared<FIDSAssetTypeActions_IDSInformationBundle>(InfodemicEditorCategoryBit),
		MakeShared<FIDSAssetTypeActions_IDSNode>(InfodemicEditorCategoryBit)
	});
}

void FInfodemicEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FInfodemicEditorStyle::Shutdown();

	FInfodemicEditorCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(InfodemicEditorTabName);

	FAssetTypeActionRegistry::UnregisterActions(ACTION_NAMESPACE);
}

TSharedRef<SDockTab> FInfodemicEditorModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SFullGraphView)
		];
}

void FInfodemicEditorModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(InfodemicEditorTabName);
}

void FInfodemicEditorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FInfodemicEditorCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(
					FToolMenuEntry::InitToolBarButton(FInfodemicEditorCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef ACTION_NAMESPACE
#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FInfodemicEditorModule, InfodemicEditor)
