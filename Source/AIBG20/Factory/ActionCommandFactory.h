// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include <string>
#include <iostream>    
#include <sstream> 
#include "../Command/ActionCommand.h"
#include "../Entity/GamePlayer.h"

#include "Json.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
#include "../InputDTO/ActionDTO.h"

using namespace std;
/**
 * 
 */
class AIBG20_API ActionCommandFactory 
{
public:
	// field : Type;
	ActionCommandFactory();
	~ActionCommandFactory();
	
	virtual TArray<ActionCommand*> CreateActionCommand(FString action, AGamePlayer* player);


protected:
	virtual bool IsValidCommand(FActionDTO actionDto);

	vector<string> getParsedData(FString action);
	//validating if the command is valid, not if the 

	//action can be triggered
};
