// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantService.h"
#include "../Entity/PlantCards/TestPlantCard.h"
#include "../Entity/Plants/TestPlant.h"
#include "../Defines.h"

PlantService::PlantService()
{
}

PlantService::~PlantService()
{
}

APlant* PlantService::SpawnPlant(UWorld* world,int plantCardId, int x, int y)
{

	FActorSpawnParameters spawnparams;
	FVector location = FVector(-401.0 + x * 49, -231.0 + y * 49, 449.0);
	FRotator rotation = FRotator(0, 0, 0);
	UBlueprint* GeneratedBP = GenerateBlueprint(plantCardId);
	if (GeneratedBP) {
		return world->SpawnActor<APlant>(GeneratedBP->GeneratedClass, location, rotation, spawnparams);
	}
	return Cast<APlant>(GeneratedBP);
}

UBlueprint* PlantService::GenerateBlueprint(int plantCardId) {
	UObject* spawnActor = nullptr;

	switch (plantCardId) {
	case TESTPLANT_CARD_ID:
		spawnActor = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/StarterContent/Blueprints/Play/Plants/BP_TestPlant")));
		break;
	default:
		break;
	}

	if (!spawnActor)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("CANT FIND OBJECT TO SPAWN")));
		return nullptr;
	}
	return Cast<UBlueprint>(spawnActor);
}

PlantService* PlantService::getInstance()
{
	if (instance == nullptr) {
		instance = new PlantService;
	}
	return instance;
}

PlantService* PlantService::instance = 0;
