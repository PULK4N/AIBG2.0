// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Factory/ActionCommandFactory.h"
#include "../Factory/WateringCommandFactory.h"
#include "../Factory/BuyingCommandFactory.h"
#include "../Factory/PlantingCommandFactory.h"
#include "../Factory/FertilizerCommandFactory.h"
#include "../Factory/MoleCommandFactory.h"
#include "../Factory/BuyingCommandFactory.h"
#include "../Factory/HarvestingCommandFactory.h"
#include "../Factory/BuyingLandCommandFactory.h"

#define WAIT_TIME 0.5

class AIBG20_API FactoryService
{
private:
	WateringCommandFactory* wateringCommandFactory;
	
	BuyingCommandFactory* buyingCommandFactory;
	
	PlantingCommandFactory* plantingCommandFactory;
	
	FertilizerCommandFactory* fertilizerCommandFactory;
	
	MoleCommandFactory* moleCommandFactory;
	
	HarvestingCommandFactory* harvestingCommandFactory;
	
	BuyingLandCommandFactory* buyingLandCommandFactory;

public:
	FactoryService();
	~FactoryService();

    ActionCommandFactory* InputAction(FString action, AGamePlayer *player);
};