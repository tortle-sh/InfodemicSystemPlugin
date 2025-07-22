// Fill out your copyright notice in the Description page of Project Settings.


#include "db/InfodemicDbSubsystem.h"

#include "InfodemicCore.h"
#include "db/InfodemicDbConfig.h"


void UInfodemicDbSubsystem::Setup(FSubsystemCollectionBase& Collection)
{
	FInfodemicDbConfigStruct Config = {};
	Config.Load();

	const FSoftClassPath TestClass = FSoftClassPath(UInfodemicDbAdapter::StaticClass());
	
	const FSoftClassPath  Adapter = FSoftClassPath(Config.InfodemicDbClassPath);
	UClass* AdapterClass = Adapter.ResolveClass();

	if(AdapterClass == nullptr)
	{
		UE_LOG(InfodemicCore, Error, TEXT("Class '%s' is currently not loaded!"), *Config.InfodemicDbClassPath);
		return;
	}

	if(AdapterClass->GetSuperClass() != UEngineSubsystem::StaticClass())
	{
		UE_LOG(InfodemicCore, Error, TEXT("Class %s is not a child of UEngineSubsystem"), *Config.InfodemicDbClassPath);
		return;
	}

	if(!AdapterClass->ImplementsInterface(UInfodemicDbAdapter::StaticClass()))
	{
		UE_LOG(InfodemicCore, Error, TEXT("Class specified with DbSubsystemClassPath, doesn't implement IInfodemicDbAdapter"));
		return;
	}

	Collection.InitializeDependency(AdapterClass);
	IInfodemicDbAdapter* AdapterInterface = Cast<IInfodemicDbAdapter>(GEngine->GetEngineSubsystemBase(AdapterClass));

	if(AdapterInterface == nullptr)
	{
		UE_LOG(InfodemicCore, Error, TEXT("Subsystem '%s' is not initialized!"), *Config.InfodemicDbClassPath);
		return;
	}

	this->InfodemicDb = AdapterInterface;
	this->InfodemicDb->Ping();
}

bool UInfodemicDbSubsystem::IsDbInitialized() const
{
	return this->InfodemicDb != nullptr;
}

void UInfodemicDbSubsystem::Ping() const
{
	check(IsDbInitialized());
	this->InfodemicDb->Ping();
}

void UInfodemicDbSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(InfodemicCore, Display, TEXT("InfodemicDbSubsystem Initialize"))
	Setup(Collection);
}

void UInfodemicDbSubsystem::SendQueries(const TArray<FString>& Queries, bool bIsWriteMode) const
{
	check(IsDbInitialized());
	this->InfodemicDb->SendQueries(Queries, bIsWriteMode);
}

void UInfodemicDbSubsystem::PurgeDb() const
{
	check(IsDbInitialized());
	this->InfodemicDb->PurgeDb();
}

void UInfodemicDbSubsystem::PersistBundle(const UIDS_InformationBundle* Bundle) const 
{
	check(IsDbInitialized());
	this->InfodemicDb->PersistBundle(Bundle);
}

void UInfodemicDbSubsystem::PersistCollection(UIDS_InformationCollection* Collection) const
{
	check(IsDbInitialized());
	this->InfodemicDb->PersistCollection(Collection);
}
