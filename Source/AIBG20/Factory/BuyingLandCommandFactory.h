// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionCommandFactory.h"
#include "../Command/BuyingLandActionCommand.h"
#include "../Entity/PlantCard.h"
#include "../Entity/GamePlayer.h"
#include <string>
using namespace std;
/**
 * 
 */
class AIBG20_API BuyingLandCommandFactory : public ActionCommandFactory
{
public:
	BuyingLandCommandFactory();
	~BuyingLandCommandFactory();

	TArray<ActionCommand*> CreateActionCommand(FString action, AGamePlayer* player);
};
