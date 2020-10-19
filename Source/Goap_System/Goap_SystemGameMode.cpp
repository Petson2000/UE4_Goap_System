// Copyright Epic Games, Inc. All Rights Reserved.

#include "Goap_SystemGameMode.h"
#include "Goap_SystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGoap_SystemGameMode::AGoap_SystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
