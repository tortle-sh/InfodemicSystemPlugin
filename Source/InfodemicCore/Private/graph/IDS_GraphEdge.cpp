// Fill out your copyright notice in the Description page of Project Settings.


#include "graph/IDS_GraphEdge.h"

UIDS_GraphEdge::UIDS_GraphEdge()
{
}

void UIDS_GraphEdge::SetNodeTitleToIdsRelationTitle()
{
		if(IdsRelation.IsValid())
		{
			bShouldDrawTitle = true;
			SetNodeTitle(IdsRelation->GetTitle());
		}
		else
		{
			bShouldDrawTitle = false;
			SetNodeTitle(FText::FromString(""));
		}
}

void UIDS_GraphEdge::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if(PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDS_GraphEdge, IdsRelation))
	{
		SetNodeTitleToIdsRelationTitle();
	}
}
