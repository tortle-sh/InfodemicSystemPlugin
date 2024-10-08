// Fill out your copyright notice in the Description page of Project Settings.


#include "InformationBundle/Factory_IDS_InformationBundle.h"
#include "InfodemicCore/Public/base/IDS_InformationBundle.h"

#define LOCTEXT_NAMESPACE "InformationBundleFactory"

UFactory_IDS_InformationBundle::UFactory_IDS_InformationBundle()
{
	bCreateNew = true;
	SupportedClass = UIDS_InformationBundle::StaticClass();
}

UObject* UFactory_IDS_InformationBundle::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
                                                  UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UIDS_InformationBundle>(InParent, InClass, InName, Flags, Context);
}

bool UFactory_IDS_InformationBundle::ConfigureProperties()
{
	return true;
}

#undef LOCTEXT_NAMESPACE