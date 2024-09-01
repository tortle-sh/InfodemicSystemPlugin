// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InfodemicCore/Public/base/nodes/IDSNode.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Factory_IDSNode.generated.h"

/**
 * 
 */
UCLASS()
class INFODEMICEDITOR_API UFactory_IDSNode : public UFactory
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category=DataAsset)
	TSubclassOf<UIDSNode> NodeClass;

	UFactory_IDSNode();
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ConfigureProperties() override;
};
