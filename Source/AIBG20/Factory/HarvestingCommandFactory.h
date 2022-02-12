// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionCommandFactory.h"
#include "../Command/ActionCommand.h"
#include "../Command/HarvestingActionCommand.h"
#include "../Entity/GamePlayer.h"
/**
 * 
 */
class AIBG20_API HarvestingCommandFactory : public ActionCommandFactory
{
public:
	HarvestingCommandFactory();
	~HarvestingCommandFactory();

	TArray<ActionCommand*> CreateActionCommand(FString action, AGamePlayer* player);
private:
	virtual bool IsValidCommand(FActionDTO actionDto) override;
};
