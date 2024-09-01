// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "base/nodes/IDSNode.h"
#include "UObject/Object.h"
#include "GenericGraphRuntime/Public/GenericGraphNode.h"
#include "IDSGraphNode.generated.h"

/**
 * 
 */
UCLASS()
class INFODEMICCORE_API UIDSGraphNode : public UGenericGraphNode
{
	GENERATED_BODY()

protected:
	UIDSGraphNode();
	void SetNodeTitleToIdsNodeTitle();

public:
	UPROPERTY(EditAnywhere)
	TWeakObjectPtr<UIDSNode> IdsNode;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	
};
