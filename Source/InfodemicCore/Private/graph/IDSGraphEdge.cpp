// Fill out your copyright notice in the Description page of Project Settings.


#include "graph/IDSGraphEdge.h"

UIDSGraphEdge::UIDSGraphEdge()
{
}

void UIDSGraphEdge::SetNodeTitleToIdsRelationTitle()
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

void UIDSGraphEdge::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if(PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDSGraphEdge, IdsRelation))
	{
		SetNodeTitleToIdsRelationTitle();
	}
}
