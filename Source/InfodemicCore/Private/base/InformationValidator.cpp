// Copyright 2024 tortle-sh. All Rights Reserved


#include "base/InformationValidator.h"

#include "base/IDS_InformationBundle.h"

bool UInformationValidator::CanValidateAsset_Implementation(const FAssetData& InAssetData, UObject* InObject,
                                                            FDataValidationContext& InContext) const
{
	if (InObject->GetClass()->IsChildOf(UIDS_InformationBundle::StaticClass()))
	{
		return true;
	}

	return false;
}

EDataValidationResult UInformationValidator::ValidateLoadedAsset_Implementation(const FAssetData& InAssetData,
	UObject* InAsset, FDataValidationContext& Context)
{
	const UIDS_InformationBundle* Bundle = Cast<UIDS_InformationBundle>(InAsset);
	if (Bundle == nullptr)
	{
		AssetFails(InAsset, FText::FromString(
			           "Asset is not of type " + UIDS_InformationBundle::StaticClass()->GetName()));
		return EDataValidationResult::Invalid;
	}

	const TArray<FIDS_Information> Information = Bundle->GetInformation().Array();
	for (int i = 0; i < Information.Num(); i++)
	{
		TSoftObjectPtr<UIDS_Relation> Relation = Information[i].Relation;
		TSoftObjectPtr<UIDS_Node> StartNode = Information[i].StartNode;
		TSoftObjectPtr<UIDS_Node> EndNode = Information[i].EndNode;

		// allow information only containing a start node
		if(StartNode.IsValid() && !Relation.IsValid() && !EndNode.IsValid())
		{
			return EDataValidationResult::Valid;
		}
		
		// relation validation
		if(!Relation.IsValid())
		{
			AssetFails(InAsset, FormatFText(TEXT("\nRelation for Information [%d] is not valid!"), i));
			return EDataValidationResult::Invalid;
		}
		
		// start node validation
		if(!StartNode.IsValid())
		{
			AssetFails(InAsset, FormatFText(TEXT("\nStartNode for Information [%d] is not valid!"), i));
			return EDataValidationResult::Invalid;
		}
		
		if (!StartNode.Get()->GetNodeTypes().HasAny(Relation.Get()->GetStartNodeTypes()))
		{
			AssetFails(InAsset,FormatFText(
				TEXT("\nStartNode types of information [%d] are not compatible with used relation"), i));
			return EDataValidationResult::Invalid;
		}

		// end node validation
		if(!EndNode.IsValid())
		{
			AssetFails(InAsset, FormatFText(TEXT("\nEndNode for Information [%d] is not valid!"), i));
			return EDataValidationResult::Invalid;
		}
		
		if(!EndNode.Get()->GetNodeTypes().HasAny(Relation.Get()->GetEndNodeTypes()))
		{
			AssetFails(InAsset,FormatFText(
				TEXT("\nEndNodeTypes of information [%d] are not compatible with used relation"), i));
			return EDataValidationResult::Invalid;
		}
	}

	AssetPasses(InAsset);
	return EDataValidationResult::Valid;
}
