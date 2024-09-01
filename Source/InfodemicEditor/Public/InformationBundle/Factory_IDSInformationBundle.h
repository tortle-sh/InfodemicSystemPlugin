// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "Factory_IDSInformationBundle.generated.h"

/**
 * 
 */
UCLASS()
class INFODEMICEDITOR_API UFactory_IDSInformationBundle : public UFactory
{
	GENERATED_BODY()
	UFactory_IDSInformationBundle();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ConfigureProperties() override;
};
