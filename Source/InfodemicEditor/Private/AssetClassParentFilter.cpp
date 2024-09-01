// Fill out your copyright notice in the Description page of Project Settings.


#include "common/AssetClassParentFilter.h"

#include "Kismet2/KismetEditorUtilities.h"

FAssetClassParentFilter::FAssetClassParentFilter(): DisallowedClassFlags(CLASS_None), bDisallowBlueprintBase(false)
{
}

bool FAssetClassParentFilter::IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions,
	const UClass* InClass, TSharedRef<FClassViewerFilterFuncs> InFilterFuncs)
{
	bool bAllowed = !InClass->HasAnyClassFlags(DisallowedClassFlags)
		&& InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InClass) != EFilterReturn::Failed;

	if (bAllowed && bDisallowBlueprintBase)
	{
		if (FKismetEditorUtilities::CanCreateBlueprintOfClass(InClass))
		{
			return false;
		}
	}

	return bAllowed;
}

bool FAssetClassParentFilter::IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions,
	const TSharedRef<const IUnloadedBlueprintData> InUnloadedClassData,
	TSharedRef<FClassViewerFilterFuncs> InFilterFuncs)
{
	if (bDisallowBlueprintBase)
	{
		return false;
	}

	return !InUnloadedClassData->HasAnyClassFlags(DisallowedClassFlags)
		&& InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InUnloadedClassData) !=
		EFilterReturn::Failed;
}
