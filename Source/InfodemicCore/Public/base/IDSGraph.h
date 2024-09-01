// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericGraph.h"
#include "IDSInformationBundle.h"
#include "IDSGraph.generated.h"

UCLASS(BlueprintType)
class INFODEMICCORE_API UIDSGraph : public UGenericGraph 
{
	GENERATED_BODY()

	UIDSGraph();

	UPROPERTY(EditAnywhere, Category=Information)
	TArray<UIDSInformationBundle*> UniqueInformationCollection;

	UPROPERTY()
	TArray<UIDSInformationBundle*> InheritedInformationCollection;

	UPROPERTY(EditAnywhere, Category=Information)
	FGameplayTagContainer InheritedInformation;

	UPROPERTY()
	TArray<UIDSInformationBundle*> CombinedInformationCollection;

	UFUNCTION()
	void UpdateCombinedInformationCollection();

public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
