// Copyright 2024 tortle-sh. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UObject/Object.h"
#include "Factory_IDS_Relation.generated.h"

/**
 * 
 */
UCLASS()
class INFODEMICEDITOR_API UFactory_IDS_Relation : public UFactory
{
	GENERATED_BODY()
	UFactory_IDS_Relation();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ConfigureProperties() override;
};
