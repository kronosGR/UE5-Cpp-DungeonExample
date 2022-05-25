// Copyright Epic Games, Inc. All Rights Reserved.

#include "DungeonExampleGameMode.h"
#include "DungeonExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADungeonExampleGameMode::ADungeonExampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
