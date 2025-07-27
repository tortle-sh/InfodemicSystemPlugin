// Fill out your copyright notice in the Description page of Project Settings.


#include "InformationCollection/Factory_IDS_InformationCollection.h"
#include "base/IDS_InformationCollection.h"

#define LOCTEXT_NAMESPACE "InformationCollectionFactory"

UFactory_IDS_InformationCollection::UFactory_IDS_InformationCollection()
{
	bCreateNew = true;
	SupportedClass = UIDS_InformationCollection::StaticClass();
}

UObject* UFactory_IDS_InformationCollection::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return Super::FactoryCreateNew(InClass, InParent, InName, Flags, Context, Warn);
}

bool UFactory_IDS_InformationCollection::ConfigureProperties()
{
	return Super::ConfigureProperties();
}

#undef LOCTEXT_NAMESPACE