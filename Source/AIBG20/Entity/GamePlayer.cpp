// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayer.h"
#include "../Server/TCPSocket.h"
#include "../InputServices/InputService.h"
#include "Fertilizer.h"
#include "Mole.h"
#include "Water.h"
#include "../Service/PlantService.h"
#include "./PlantCards/TestPlantCard.h"
#include "./PlantCards/AnemoneFlowerPlantCard.h"
#include "./PlantCards/BlueJazzPlantCard.h"
#include "./PlantCards/CrocusFlowerPlantCard.h"
#include "./PlantCards/TulipPlantCard.h"

// Sets default values
AGamePlayer::AGamePlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SetActorHiddenInGame(true);
	
}


void AGamePlayer::BuyCard(int id, int amount)
{
	FindCardById(id)->Owned += amount;
}

void AGamePlayer::BuyTile(ATile* tile)
{
	Tiles.Add(tile);
}

void AGamePlayer::PlacePlant(int cardId, int x, int y, ATile* tile)
{
	APlant* plant = plantService->SpawnPlant(cardId, x, y);
	tile->bIsPlanted = true;
	tile->Plant = plant;
}

void AGamePlayer::WaterPlant(int drops, ATile* tile)
{
	tile->Plant->Water(drops);
}

void AGamePlayer::HarvestPlants()
{
	for (ATile* tile : Tiles) {
		if (tile->bIsPlanted) {
			if (tile->Plant->PlantState == APlant::ST_ROTTEN || tile->Plant->PlantState == APlant::ST_READY_FOR_HARVEST) {
				int HarvestValue = tile->Plant->Harvest();
				Gold += HarvestValue * ((FertilizerActive > 0) + 1) * ((Cast<ASpecialTile>(tile) != nullptr) + 1);
				Points += HarvestValue;
				tile->Plant->Destroy();
				tile->bIsPlanted = false;
			}
		}
	}
}

void AGamePlayer::AddFertilizer()
{
	FertilizerActive += 3;
}

void AGamePlayer::DecrementFertilizer()
{
	if (FertilizerActive > 0)
		FertilizerActive--;
}

// Called when the game starts or when spawned
void AGamePlayer::BeginPlay()
{
	Super::BeginPlay();
	plantService = GetWorld()->SpawnActor<APlantService>(plantServiceToSpawn);
	AddCards();
}
//TO DO: remove owned cards changes
void AGamePlayer::AddCards()
{
	Cards.Add(GetWorld()->SpawnActor<AFertilizer>(AFertilizer::StaticClass()));
	Cards.Add(GetWorld()->SpawnActor<AMole>(AMole::StaticClass()));
	Cards.Add(GetWorld()->SpawnActor<AWater>(AWater::StaticClass()));
	Cards.Add(GetWorld()->SpawnActor<ATestPlantCard>(ATestPlantCard::StaticClass()));
	Cards.Add(GetWorld()->SpawnActor<AAnemoneFlowerPlantCard>(AAnemoneFlowerPlantCard::StaticClass()));
	Cards.Add(GetWorld()->SpawnActor<ABlueJazzPlantCard>(ABlueJazzPlantCard::StaticClass()));
	Cards.Add(GetWorld()->SpawnActor<ACrocusFlowerPlantCard>(ACrocusFlowerPlantCard::StaticClass()));
	Cards.Add(GetWorld()->SpawnActor<ATulipPlantCard>(ATulipPlantCard::StaticClass()));
}

// Called every frame
void AGamePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGamePlayer::InstantiateSocket(FString port) {
	FActorSpawnParameters Spawnparams;
	FVector location = FVector(0, 0, 0);
	FRotator rotation = FRotator(0, 0, 0);
	Socket = GetWorld()->SpawnActor<ATCPSocket>(TcpSocketActorToSpawn, location, rotation, Spawnparams);
	Socket->LaunchTCP(port, this);
}

ACard* AGamePlayer::FindCardById(int id)
{
	for (ACard* card : Cards) {
		if (card->Id == id)
			return card;
	}
	return nullptr;
}
