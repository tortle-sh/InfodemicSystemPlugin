// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InfodemicCore/Public/base/nodes/IDS_Node.h"
#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UObject/Object.h"
#include "Factory_IDS_Node.generated.h"

/**
 * 
 */
UCLASS()
class INFODEMICEDITOR_API UFactory_IDS_Node : public UFactory
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category=DataAsset)
	TSubclassOf<UIDS_Node> NodeClass;

	UFactory_IDS_Node();
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ConfigureProperties() override;
};
