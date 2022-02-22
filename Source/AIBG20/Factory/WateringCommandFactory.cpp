// Fill out your copyright notice in the Description page of Project Settings.


#include "WateringCommandFactory.h"
#include "../Defines.h"

WateringCommandFactory::WateringCommandFactory()
{
}

WateringCommandFactory::~WateringCommandFactory()
{
}

TArray<ActionCommand*> WateringCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
	FActionDTO actionDto;
	bool converted = FJsonObjectConverter::JsonObjectStringToUStruct(action, &actionDto, 0, 0);

	TArray<ActionCommand*> commands;

	if (IsValidCommand(actionDto)) {
		for (FActionPropertyDTO actionProperty : actionDto.Properties) {
			commands.Add(new WateringActionCommand(player, actionProperty.X, actionProperty.Y, WATER_CARD_ID, actionProperty.Amount));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s: Error - invalid watering action typed"), *player->Name);
	}
	return commands;
}