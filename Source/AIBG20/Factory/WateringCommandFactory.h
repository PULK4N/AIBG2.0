// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionCommandFactory.h"
#include <string>
#include <vector>
#include "WateringActionCommand.h"
#include "../Entity/Water.h"

using namespace std;
/**
 *
 */
class AIBG20_API WateringCommandFactory : public ActionCommandFactory
{
public:
	WateringCommandFactory();
	~WateringCommandFactory();

	TArray<ActionCommand> CreateActionCommand(FString action, AGamePlayer* player);
private:
	bool IsValidCommand(FString action);
};
