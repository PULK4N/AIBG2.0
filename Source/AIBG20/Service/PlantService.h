// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class APlant;
class APlantCard;
/**
 * 
 */
class AIBG20_API PlantService
{
public:
	static PlantService* getInstance();
	~PlantService();
	APlant* SpawnPlant(UWorld* world,int plantCardId, int x, int y);
private:
	PlantService();
	static PlantService* instance;
	UBlueprint* GenerateBlueprint(int plantCardId);
};
