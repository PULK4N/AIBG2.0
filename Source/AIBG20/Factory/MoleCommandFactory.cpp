// Fill out your copyright notice in the Description page of Project Settings.


#include "MoleCommandFactory.h"

MoleCommandFactory::MoleCommandFactory()
{
}

MoleCommandFactory::~MoleCommandFactory()
{
}

TArray<ActionCommand*> MoleCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
	FActionDTO actionDto;
	bool converted = FJsonObjectConverter::JsonObjectStringToUStruct(action, &actionDto, 0, 0);

	TArray<ActionCommand*> commands;

	if (IsValidCommand(actionDto)) {
		for (FActionPropertyDTO actionProperty : actionDto.Properties) {
			commands.Add(new MoleCardActionCommand(player, actionProperty.X, actionProperty.Y, MOLE_CARD_ID, 1));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s: Error - invalid mole action typed"), *player->Name);
	}
	return commands;
}

bool MoleCommandFactory::IsValidCommand(FActionDTO actionDto) {
	if (actionDto.Properties.Num() != 1)
		return false;

	for (FActionPropertyDTO actionProperty : actionDto.Properties) {

		if (actionProperty.X < 0 || actionProperty.X > 7)
			return false;

		if (actionProperty.Y < 0 || actionProperty.Y > 7)
			return false;
	}
	return true;
}


