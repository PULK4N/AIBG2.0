// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantingCommandFactory.h"

PlantingCommandFactory::PlantingCommandFactory()
{
}

PlantingCommandFactory::~PlantingCommandFactory()
{
}


TArray<ActionCommand*> PlantingCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
	FActionDTO actionDto;
	bool converted = FJsonObjectConverter::JsonObjectStringToUStruct(action, &actionDto, 0, 0);

	TArray<ActionCommand*> commands;

	if (IsValidCommand(actionDto)) {
		for (FActionPropertyDTO actionProperty : actionDto.Properties) {
			commands.Add(new PlantingActionCommand(actionProperty.CardId, actionProperty.X, actionProperty.Y,player));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s: Error - invalid planting action typed"), *player->Name);
	}
	return commands;
}