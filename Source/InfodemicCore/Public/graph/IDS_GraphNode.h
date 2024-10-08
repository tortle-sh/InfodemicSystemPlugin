// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "base/nodes/IDS_Node.h"
#include "UObject/Object.h"
#include "GenericGraphRuntime/Public/GenericGraphNode.h"
#include "IDS_GraphNode.generated.h"

/**
 * 
 */
UCLASS()
class INFODEMICCORE_API UIDS_GraphNode : public UGenericGraphNode
{
	GENERATED_BODY()

protected:
	UIDS_GraphNode();
	void SetNodeTitleToIdsNodeTitle();

public:
	UPROPERTY(EditAnywhere)
	TWeakObjectPtr<UIDS_Node> IdsNode;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	
};
