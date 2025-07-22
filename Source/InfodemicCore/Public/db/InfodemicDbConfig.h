// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfodemicDbAdapter.h"
#include "UObject/Object.h"
#include "InfodemicDbConfig.generated.h"

/**
 * 
 */
UCLASS(config=InfodemicDbConfig)
class INFODEMICCORE_API UInfodemicDbConfig : public UObject
{
	GENERATED_BODY()
public:

	UPROPERTY(Config)
	FString Url;

	UPROPERTY(Config)
	FString Username;
	
	UPROPERTY(Config)
	FString Password;
	
	UPROPERTY(Config)
	FString DbSubsystemClassPath;
};

USTRUCT()
struct FInfodemicDbConfigStruct
{
	GENERATED_BODY()
	
	FString Url;
	FString Username;
	FString Password;
	FString InfodemicDbClassPath;

	void Load()
	{
		this->Url = GConfig->GetStr(TEXT("InfodemicDbConfig"), TEXT("Url"), GEngineIni);
		this->Username = GConfig->GetStr(TEXT("InfodemicDbConfig"), TEXT("Username"), GEngineIni);
		this->Password = GConfig->GetStr(TEXT("InfodemicDbConfig"), TEXT("Password"), GEngineIni);
		
		this->InfodemicDbClassPath = GConfig->GetStr(TEXT("InfodemicDbConfig"), TEXT("DbSubsystemClassPath"), GEngineIni);
	}
};
