// Fill out your copyright notice in the Description page of Project Settings.


#include "InformationBundle/Factory_IDSInformationBundle.h"

#include "InfodemicCore/Public/base/IDSInformationBundle.h"

#define LOCTEXT_NAMESPACE "InformationBundleFactory"

UFactory_IDSInformationBundle::UFactory_IDSInformationBundle()
{
	bCreateNew = true;
	SupportedClass = UIDSInformationBundle::StaticClass();
}

UObject* UFactory_IDSInformationBundle::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
                                                  UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UIDSInformationBundle>(InParent, InClass, InName, Flags, Context);
}

bool UFactory_IDSInformationBundle::ConfigureProperties()
{
	return true;
}

#undef LOCTEXT_NAMESPACE