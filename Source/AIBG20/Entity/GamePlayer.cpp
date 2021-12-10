// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayer.h"
#include "../Server/TCPSocket.h"
#include "../Service/InputService.h"

// Sets default values
AGamePlayer::AGamePlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Tiles = TArray<ATile*>();
	Cards = TArray<ACard*>();
	inputService = inputService->getInstance();
	
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

void AGamePlayer::PlacePlant(int CardId, int x, int y)
{
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
				if (FertilizerActive > 0) {
					Gold += HarvestValue * 2;
				}
				else {
					Gold += HarvestValue;
				}
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

// Called when the game starts or when spawned
void AGamePlayer::BeginPlay()
{
	Super::BeginPlay();
	
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
