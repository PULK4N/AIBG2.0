// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingCommandFactory.h"

BuyingCommandFactory::BuyingCommandFactory()
{
}

BuyingCommandFactory::~BuyingCommandFactory()
{
}

TArray<ActionCommand*> BuyingCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
	FActionDTO actionDto;
	bool converted = FJsonObjectConverter::JsonObjectStringToUStruct(action, &actionDto, 0, 0);

	TArray<ActionCommand*> commands;
	if (IsValidCommand(actionDto)) {
		for (FActionPropertyDTO actionProperty : actionDto.Properties) {
			commands.Add(new BuyingActionCommand(actionProperty.CardId, actionProperty.Amount, player));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s: Error - invalid buying action typed"), *player->Name);
	}
	return commands;
}
