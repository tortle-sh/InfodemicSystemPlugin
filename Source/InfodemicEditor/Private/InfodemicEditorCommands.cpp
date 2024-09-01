// Copyright Epic Games, Inc. All Rights Reserved.

#include "InfodemicEditorCommands.h"

#define LOCTEXT_NAMESPACE "FInfodemicEditorModule"

void FInfodemicEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "InfodemicEditor", "Bring up InfodemicEditor window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
