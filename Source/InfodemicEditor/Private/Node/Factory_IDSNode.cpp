// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/Factory_IDSNode.h"

#include "common/AssetClassParentFilter.h"
#include "ClassViewerModule.h"
#include "base/nodes/IDSNode.h"
#include "Kismet2/SClassPickerDialog.h"

#define LOCTEXT_NAMESPACE "UIDSNodeFactory"

UFactory_IDSNode::UFactory_IDSNode()
{
	bCreateNew = true;
	SupportedClass = UIDSNode::StaticClass();
}

UObject* UFactory_IDSNode::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
                                           UObject* Context, FFeedbackContext* Warn)
{
	if(NodeClass != nullptr)
	{
		return NewObject<UIDSNode>(InParent, NodeClass, InName, Flags | RF_Transactional);
	}

	check(InClass->IsChildOf(UIDSNode::StaticClass()));
	return NewObject<UIDSNode>(InParent, InClass, InName, Flags, Context);
}

bool UFactory_IDSNode::ConfigureProperties()
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
	Filter->AllowedChildrenOfClasses.Add(UIDSNode::StaticClass());

	const FText TitleText = LOCTEXT("CreateIdsNodeAssetOptions", "Pick an IDS Node");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk =  SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UIDSNode::StaticClass());

	if (bPressedOk)
	{
		NodeClass = ChosenClass;
	}
	
	return bPressedOk;
}

#undef LOCTEXT_NAMESPACE
