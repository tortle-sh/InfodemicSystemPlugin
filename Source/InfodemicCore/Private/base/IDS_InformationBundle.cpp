#include "base/IDS_InformationBundle.h"

void UIDS_InformationBundle::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	UE_LOG(LogTemp, Display, TEXT("%s loaded"), *GetFName().ToString());
	InformationCategories.InitializeSubject();
}

void UIDS_InformationBundle::OnDeleteAsset_Implementation()
{
	this->InformationCategories.DeinitializeSubject();
}

void UIDS_InformationBundle::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);

	if (PropertyAboutToChange->GetFName() == GET_MEMBER_NAME_CHECKED(FAssetTagSubject, TagContainer))
	{
		InformationCategories.PreEditChange();
	}
}

void UIDS_InformationBundle::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDS_InformationBundle, InformationCategories))
	{
		InformationCategories.PostEditChangeProperty(PropertyChangedEvent);
	}
}

const TArray<FIDS_Information>& UIDS_InformationBundle::GetInformation() const
{
	return this->Information;
}
