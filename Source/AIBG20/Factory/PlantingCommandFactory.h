// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionCommandFactory.h"
#include "../Command/PlantingActionCommand.h"
#include "../Entity/GamePlayer.h"
/**
 * 
 */
class AIBG20_API PlantingCommandFactory : public ActionCommandFactory
{
public:
	PlantingCommandFactory();
	~PlantingCommandFactory();
	TArray<ActionCommand*> CreateActionCommand(FString action, AGamePlayer* player);
private:
	virtual bool IsValidCommand(FActionDTO actionDto) override;
};
