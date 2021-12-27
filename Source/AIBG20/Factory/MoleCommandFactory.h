// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionCommandFactory.h"
#include <string>
#include <vector>
#include "../Entity/Mole.h"
#include "../Command/MoleCardActionCommand.h"
#include "../Entity/GamePlayer.h"

using namespace std;
/**
 *
 */
class AIBG20_API MoleCommandFactory : public ActionCommandFactory
{
public:
	MoleCommandFactory();
	~MoleCommandFactory();

	TArray<ActionCommand> CreateActionCommand(FString action, AGamePlayer* player);
private:
	bool IsValidCommand(FString action);
};
