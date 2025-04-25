// Copyright 2024 tortle-sh. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "base/IDS_Information.h"
#include "base/IDS_InformationBundle.h"
#include "UObject/Object.h"
#include "IDS_Graph.generated.h"

/**
 * 
 */
UCLASS()
class INFODEMICCORE_API UIDS_Graph : public UObject
{
	GENERATED_BODY()

	TSet<FIDS_Information> InformationTriplets;
	

	void BuildGraph(const TSet<UIDS_InformationBundle>& Bundles);
};
