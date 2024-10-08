// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/Factory_IDS_Node.h"

#include "common/AssetClassParentFilter.h"
#include "ClassViewerModule.h"
#include "base/nodes/IDS_Node.h"
#include "Kismet2/SClassPickerDialog.h"

#define LOCTEXT_NAMESPACE "UIDSNodeFactory"

UFactory_IDS_Node::UFactory_IDS_Node()
{
	bCreateNew = true;
	SupportedClass = UIDS_Node::StaticClass();
}

UObject* UFactory_IDS_Node::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
                                           UObject* Context, FFeedbackContext* Warn)
{
	if(NodeClass != nullptr)
	{
		return NewObject<UIDS_Node>(InParent, NodeClass, InName, Flags | RF_Transactional);
	}

	check(InClass->IsChildOf(UIDS_Node::StaticClass()));
	return NewObject<UIDS_Node>(InParent, InClass, InName, Flags, Context);
}

bool UFactory_IDS_Node::ConfigureProperties()
{
	FModuleManager::LoadModuleChecked<FClassViewerModule>("ClassViewer");
	
	FClassViewerInitializationOptions Options;
	Options.Mode = EClassViewerMode::ClassPicker;

#if ENGINE_MAJOR_VERSION < 5
	return false;
#endif
	
	TSharedRef<FAssetClassParentFilter> Filter = MakeShareable(new FAssetClassParentFilter);
	
	Options.ClassFilters.Add(Filter);
	
	Filter->DisallowedClassFlags = CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists | CLASS_HideDropDown;
	Filter->AllowedChildrenOfClasses.Add(UIDS_Node::StaticClass());

	const FText TitleText = LOCTEXT("CreateIdsNodeAssetOptions", "Pick an IDS Node");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk =  SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UIDS_Node::StaticClass());

	if (bPressedOk)
	{
		NodeClass = ChosenClass;
	}
	
	return bPressedOk;
}

#undef LOCTEXT_NAMESPACE
