// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../Command/ActionCommand.h"

class AIBG20_API ActionService
{
public:
    void ExecuteActions(TArray<ActionCommand> actionCommands, AGamePlayer*player);

};