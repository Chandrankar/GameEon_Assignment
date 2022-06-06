// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameEon_Ass_LocoGameMode.h"
#include "GameEon_Ass_LocoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameEon_Ass_LocoGameMode::AGameEon_Ass_LocoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
