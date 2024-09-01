// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTagTreeContainerSubject.h"
#include "IDSInformation.h"
#include "UObject/Object.h"
#include "IDSInformationBundle.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class INFODEMICCORE_API UIDSInformationBundle : public UObject
{
	GENERATED_BODY()

public:
	UIDSInformationBundle();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=MetaData)
	FText Title;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=MetaData)
	FText Description;
	
	UPROPERTY(EditAnywhere, Category=Information)
	TArray<FUIDSInformation> Information;

	UPROPERTY(VisibleAnywhere, Category=Information)
	TWeakObjectPtr<UAssetTagTreeContainerSubject> InformationCategoriesHandler;
};

inline UIDSInformationBundle::UIDSInformationBundle()
{
	InformationCategoriesHandler = NewObject<UAssetTagTreeContainerSubject>();
}
