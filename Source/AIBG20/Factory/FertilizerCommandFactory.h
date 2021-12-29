// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionCommandFactory.h"
#include "../Command/ActionCommand.h"
#include "../Command/FertilizerCardActionCommand.h"
#include "../Entity/GamePlayer.h"
/**
 * 
 */
class AIBG20_API FertilizerCommandFactory : public ActionCommandFactory
{
public:
	FertilizerCommandFactory();
	~FertilizerCommandFactory();

	TArray<ActionCommand*> CreateActionCommand(FString action, AGamePlayer* player);
private:
	bool IsValidCommand(FString action);

};
