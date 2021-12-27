// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionCommandFactory.h"
#include "../Command/BuyingActionCommand.h"

using namespace std;
/*
C;[C1:A1];[C2:A2]...

Gde je C1, C2...
ID : Card
0  : Water
1  : Mole
2  : Fertilizer
3  : plant1
4  : plant2
5  : plant3
6  : plant4
 */
class AIBG20_API BuyingCommandFactory : public ActionCommandFactory
{
public:
	BuyingCommandFactory();
	~BuyingCommandFactory();
	TArray<ActionCommand> BuyingCommandFactory::CreateActionCommand(FString action, AGamePlayer* player);
private:
	virtual bool IsValidCommand(FString action);
	
};
