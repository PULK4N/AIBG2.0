// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandFactory.h"
#include "../Command/ActionCommand.h"



TArray<ActionCommand> ActionCommandFactory::CreateActionCommand(FString action, AGamePlayer *player) {
	TArray<ActionCommand> t;
	return t;
}

bool ActionCommandFactory::IsValidCommand(FString action) {
	return true;
}

