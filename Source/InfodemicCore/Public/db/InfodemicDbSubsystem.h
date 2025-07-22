// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfodemicDbAdapter.h"
#include "Subsystems/EngineSubsystem.h"
#include "InfodemicDbSubsystem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class INFODEMICCORE_API UInfodemicDbSubsystem : public UEngineSubsystem, public IInfodemicDbAdapter
{
	GENERATED_BODY()
	IInfodemicDbAdapter* InfodemicDb;
	
	void Setup(FSubsystemCollectionBase &Collection);
	bool IsDbInitialized() const;

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Ping() const override;
	
	virtual void SendQueries(const TArray<FString>& Queries, bool bIsWriteMode) const override;
	
	UFUNCTION(BlueprintCallable)
	virtual void PurgeDb() const override;
	
	UFUNCTION(BlueprintCallable)
	virtual void PersistBundle(const UIDS_InformationBundle* Bundle) const override;
	
	UFUNCTION(BlueprintCallable)
	virtual void PersistCollection(UIDS_InformationCollection* Collection) const override;
};
