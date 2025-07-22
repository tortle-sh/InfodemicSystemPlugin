// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "db/InfodemicDbAdapter.h"
#include "Subsystems/EngineSubsystem.h"
#include "InfodemicCore/Public/db/InfodemicDbConfig.h"
#include "InfodemicDb_Neo4j_Subsystem.generated.h"

UCLASS()
class INFODEMICNEO4JCONNECTOR_API UInfodemicDb_Neo4j_Subsystem : public UEngineSubsystem, public IInfodemicDbAdapter
{
	GENERATED_BODY()
	FInfodemicDbConfigStruct Config;

	virtual void PostLoad() override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	static void BuildHeaders(TMap<FString, FString> &Header, bool bAccessModeWrite = false);
	static FString FormatQueries(const TArray<FString>& Queries);
	static FString EscapeJsonString(const FString &Query);
	
	static FString CreateNodePropertyString(UIDS_Node* Node);
	static FString CreateNodeTypeString(UIDS_Node* Node);
	static FString ExtractNodeId(UIDS_Node* Node);
	static FText ExtractRelationName(UIDS_Relation* Relation);
	static void AddNodeCreationQueries(TArray<FString> &Queries, TSet<UIDS_Node*> &Nodes);
	static void AddRelationCreationQueries(TArray<FString> &Queries, TSet<FIDS_Information> &Information);
	
	UFUNCTION()
	void PrintResponse(const FString &ResponseContent, bool bSuccess);
	
	
public:
	virtual void SendQueries(const TArray<FString>& Queries, bool bAccessModeWrite) const override;
	virtual void Ping() const override;
	virtual void PurgeDb() const override;

	virtual void PersistBundle(const UIDS_InformationBundle* Bundle) const override;
	virtual void PersistCollection(UIDS_InformationCollection* Collection) const override;
};
