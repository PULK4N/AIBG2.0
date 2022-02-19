// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingLandCommandFactory.h"

BuyingLandCommandFactory::BuyingLandCommandFactory()
{
}

BuyingLandCommandFactory::~BuyingLandCommandFactory()
{
}

TArray<ActionCommand*> BuyingLandCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
	FActionDTO actionDto;
	bool converted = FJsonObjectConverter::JsonObjectStringToUStruct(action, &actionDto, 0, 0);

	TArray<ActionCommand*> commands;
	if (IsValidCommand(actionDto)) {
		for (FActionPropertyDTO actionProperty : actionDto.Properties) {
			commands.Add(new BuyingLandActionCommand(player, actionProperty.X, actionProperty.Y, 1));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s: Error - invalid buying land action typed"), *player->Name);
	}
	return commands;
}
