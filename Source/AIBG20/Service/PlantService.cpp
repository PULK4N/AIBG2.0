// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantService.h"
#include "../Entity/Plant.h"
#include "../defines.h"

// Sets default values
APlantService::APlantService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APlantService::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlantService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

APlant* APlantService::SpawnPlant(int plantCardId, int x, int y) {
	FActorSpawnParameters spawnparams;
	FVector location = FVector(-401.0 - x * 49, -231.0 + y * 49, 449.0);
	FRotator rotation = FRotator(0, 0, 0);

	switch (plantCardId) {
	case TESTPLANT_CARD_ID:
		return GetWorld()->SpawnActor<APlant>(TestPlant, location, rotation, spawnparams);
		break;
	case ANEMONE_FLOWER_CARD_ID:
		return GetWorld()->SpawnActor<APlant>(TestPlant, location, rotation, spawnparams);
		break;
	case BLUE_JAZZ_CARD_ID:
		return GetWorld()->SpawnActor<APlant>(TestPlant, location, rotation, spawnparams);
		break;
	case CROCUS_FLOWER_CARD_ID:
		return GetWorld()->SpawnActor<APlant>(TestPlant, location, rotation, spawnparams);
		break;
	case TULIP_CARD_ID:
		return GetWorld()->SpawnActor<APlant>(TestPlant, location, rotation, spawnparams);
		break;
	default:
		break;
	}
	return nullptr;
}