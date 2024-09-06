#include "base/IDSInformationBundle.h"

#include "InfodemicAssetManager.h"

void UIDSInformationBundle::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	UE_LOG(LogTemp, Display, TEXT("%s loaded"), *GetFName().ToString());
	InformationCategories.InitializeSubject(this);
}

void UIDSInformationBundle::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);

	if (PropertyAboutToChange->GetFName() == GET_MEMBER_NAME_CHECKED(FAssetTagTreeContainerSubject, TagContainer))
	{
		InformationCategories.PreEditChange();
	}
}

void UIDSInformationBundle::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(UIDSInformationBundle, InformationCategories))
	{
		InformationCategories.PostEditChangeProperty(this, PropertyChangedEvent);
	}
}
