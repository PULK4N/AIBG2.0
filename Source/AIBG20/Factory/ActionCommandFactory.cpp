// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandFactory.h"
#include "../Command/ActionCommand.h"



ActionCommandFactory::ActionCommandFactory()
{
}

ActionCommandFactory::~ActionCommandFactory()
{
	UE_LOG(LogTemp, Warning, TEXT("ActionCommandFactory deleted"));
}

TArray<ActionCommand*> ActionCommandFactory::CreateActionCommand(FString action, AGamePlayer *player) {
	TArray<ActionCommand*> t;
	return t;
}
/*
* TODO: change cardId hard coded stuff like biggest cardId and lowset cardId
*/
bool ActionCommandFactory::IsValidCommand(FActionDTO actionDto) {
	if (actionDto.Properties.Num() == 0)
		return false;

	UE_LOG(LogTemp, Warning, TEXT("%d"), actionDto.Properties.Num());

	for (FActionPropertyDTO actionProperty : actionDto.Properties) {
		if (actionProperty.Amount < 0) 
			return false;

		if (actionProperty.X < 0 || actionProperty.X > 7)
			return false;

		if (actionProperty.Y < 0 || actionProperty.Y > 7)
			return false;
	}
	return true;
}