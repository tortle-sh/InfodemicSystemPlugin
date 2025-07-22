// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "base/IDS_InformationBundle.h"
#include "base/IDS_InformationCollection.h"
#include "UObject/Interface.h"
#include "InfodemicDbAdapter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDbCallback, const FString&, Response, bool, bSuccessful);

// This class does not need to be modified.
UINTERFACE()
class UInfodemicDbAdapter : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INFODEMICCORE_API IInfodemicDbAdapter
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Ping() const = 0;
	virtual void SendQueries(const TArray<FString>& Queries, bool bIsWriteMode = false) const = 0;
	virtual void PurgeDb() const = 0;
	virtual void PersistBundle(const UIDS_InformationBundle* Bundle) const = 0;
	virtual void PersistCollection(UIDS_InformationCollection* Collection) const = 0;
};
