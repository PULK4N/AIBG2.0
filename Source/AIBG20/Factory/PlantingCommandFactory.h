// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionCommandFactory.h"
/**
 * 
 */
class AIBG20_API PlantingCommandFactory : public ActionCommandFactory
{
public:
	PlantingCommandFactory();
	~PlantingCommandFactory();
	TArray<ActionCommand> PlantingCommandFactory::CreateActionCommand(FString action, AGamePlayer* player);
private:
	virtual bool IsValidCommand(FString action);
};
