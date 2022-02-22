// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommand.h"
#include "../GameMode/GameMap.h"

ActionCommand::ActionCommand()
{
}

ActionCommand::~ActionCommand()
{
}

bool ActionCommand::CanExecute()
{
	return false;
}

void ActionCommand::Execute()
{
}
AGameMap* ActionCommand::GameMap = nullptr;