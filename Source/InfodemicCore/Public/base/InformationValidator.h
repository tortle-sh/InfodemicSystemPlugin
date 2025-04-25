// Copyright 2024 tortle-sh. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EditorValidatorBase.h"
#include "InformationValidator.generated.h"

/**
 * 
 */
UCLASS()
class INFODEMICCORE_API UInformationValidator : public UEditorValidatorBase
{
	GENERATED_BODY()


	virtual bool CanValidateAsset_Implementation(const FAssetData& InAssetData, UObject* InObject, FDataValidationContext& InContext) const override;
	virtual EDataValidationResult ValidateLoadedAsset_Implementation(const FAssetData& InAssetData, UObject* InAsset, FDataValidationContext& Context) override;

	template <typename FmtType, typename... Types>
	[[nodiscard]] static FText FormatFText(const FmtType& Fmt, Types... Args)
	{
		return FText::FromString(FString::Printf(Fmt, Args...));
	}
};
