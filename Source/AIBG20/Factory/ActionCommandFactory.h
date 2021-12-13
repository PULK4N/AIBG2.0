// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
class ActionCommand;
class AGamePlayer;
/**
 * 
 */
class AIBG20_API ActionCommandFactory 
{
public:
	// field : Type;
	
	virtual TArray<ActionCommand> CreateActionCommand(FString action, AGamePlayer* player);


protected:
	virtual bool IsValidCommand(FString action);


	//validating if the command is valid, not if the 

	//action can be triggered
};
