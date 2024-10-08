// Copyright 2024 tortle-sh. All Rights Reserved


#include "InformationRelation/Factory_IDS_Relation.h"

#include "base/IDS_Relation.h"

UFactory_IDS_Relation::UFactory_IDS_Relation()
{
	bCreateNew = true;
	SupportedClass = UIDS_Relation::StaticClass();
}

UObject* UFactory_IDS_Relation::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UIDS_Relation>(InParent, InClass, InName, Flags, Context);
}

bool UFactory_IDS_Relation::ConfigureProperties()
{
	return true;
}
