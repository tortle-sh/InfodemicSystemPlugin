// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "base/IDSGraph.h"
#include "base/IDSInformationBundle.h"
#include "UObject/Interface.h"
#include "MemoryInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UMemoryInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INFODEMICCORE_API IMemoryInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ShareInformation(const UIDSInformationBundle* InformationBundle);
};
