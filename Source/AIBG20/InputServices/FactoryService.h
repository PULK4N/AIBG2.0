// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Factory/ActionCommandFactory.h"

#define WAIT_TIME 0.5

class AIBG20_API FactoryService
{
public:
	FactoryService();
	~FactoryService();

    ActionCommandFactory* InputAction(FString action, AGamePlayer *player);
    ActionCommandFactory actionCommandFactory;
};