// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessRunnerYTGameMode.h"
#include "EndlessRunnerYTCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRunnerYTGameMode::AEndlessRunnerYTGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
