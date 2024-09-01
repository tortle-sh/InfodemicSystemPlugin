// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "InfodemicEditorStyle.h"

class FInfodemicEditorCommands : public TCommands<FInfodemicEditorCommands>
{
public:

	FInfodemicEditorCommands()
		: TCommands<FInfodemicEditorCommands>(TEXT("InfodemicEditor"), NSLOCTEXT("Contexts", "InfodemicEditor", "InfodemicSystem"), NAME_None, FInfodemicEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};