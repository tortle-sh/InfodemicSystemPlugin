#include "base/IDSInformationBundle.h"

#include "InfodemicAssetManager.h"

UIDSInformationBundle::~UIDSInformationBundle()
{
	InformationCategories.DeinitializeSubject();
}

void UIDSInformationBundle::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	UE_LOG(LogTemp, Display, TEXT("%s loaded"), *GetFName().ToString());
	InformationCategories.InitializeSubject();
}

void UIDSInformationBundle::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);

	if (PropertyAboutToChange->GetFName() == GET_MEMBER_NAME_CHECKED(FGameplayTagSubject, TagContainer))
	{
		InformationCategories.PreEditChange();
	}
}

void UIDSInformationBundle::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDSInformationBundle, InformationCategories))
	{
		InformationCategories.PostEditChangeProperty(PropertyChangedEvent);
	}
}
