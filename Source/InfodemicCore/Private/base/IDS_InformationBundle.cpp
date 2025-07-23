#include "base/IDS_InformationBundle.h"

#include "InfodemicCore.h"
#include "db/InfodemicDbSubsystem.h"

void UIDS_InformationBundle::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	UE_LOG(InfodemicCore, Display, TEXT("%s loaded"), *GetFName().ToString());

	FDefaultSubjectConfig Config;
	Config.Subject = this;
	Config.BroadcastStrategy = Children;
	InformationCategories.InitializeSubject(Config);
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

	if (PropertyAboutToChange->GetFName() == GET_MEMBER_NAME_CHECKED(UIDS_InformationBundle, Information))
	{
		PreChangeInformation.Empty();
		PreChangeInformation.Append(Information);
	}
}

void UIDS_InformationBundle::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(
		UIDS_InformationBundle, InformationCategories))
	{
		InformationCategories.PostEditChangeProperty(PropertyChangedEvent);
	}

	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDS_InformationBundle, Information))
	{
		if (PreChangeInformation.Num() != Information.Num())
		{
			TSet<FIDS_Information> NewInformation = Information.Difference(PreChangeInformation);

			for (auto Info : NewInformation)
			{
				Info.Bundle = this;
			}
			
			PreChangeInformation.Empty();
			PreChangeInformation.Append(Information);
		}
	}
}

const TSet<FIDS_Information>& UIDS_InformationBundle::GetInformation() const
{
	return this->Information;
}

void UIDS_InformationBundle::LoadIntoDb() const
{
	UInfodemicDbSubsystem* DbSubsystem = GEngine->GetEngineSubsystem<UInfodemicDbSubsystem>();
	check(DbSubsystem != nullptr);

	DbSubsystem->PersistBundle(this);
}
