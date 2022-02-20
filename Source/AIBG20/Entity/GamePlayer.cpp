// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayer.h"
#include "../Server/TCPSocket.h"
#include "../InputServices/InputService.h"
#include "SpecialTile.h"
#include "Fertilizer.h"
#include "Mole.h"
#include "Water.h"
#include "../Service/PlantService.h"
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
	SetActorEnableCollision(false);
}

/*
* Increases the amount of cards player owns
* precisely Player->Cards[id]->Owned += amount
* does nothing if id is non-existed
*/
void AGamePlayer::BuyCard(int id, int amount)
{
	if(FindCardById(id))
		FindCardById(id)->Owned += amount;
}

void AGamePlayer::BuyTile(ATile* tile)
{
	Tiles.Add(tile);
}

void AGamePlayer::PlacePlant(int cardId, int x, int y, ATile* tile)
{
	APlant* plant = plantService->SpawnPlant(cardId, x, y);//Test
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
				//if fertilizer active, multiply by 2, same for if IsA special tile
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

void AGamePlayer::SendOutput(FString outputMessage)
{
	if(Socket)
		Socket->TCPSend(outputMessage);
	else
		UE_LOG(LogTemp, Warning, TEXT("Sending output to a player without socket"));
}

ACard* AGamePlayer::FindCardById(int id)
{
	for (ACard* card : Cards) {
		if (card->Id == id)
			return card;
	}
	return nullptr;
}

FGamePlayerDTO AGamePlayer::GenerateDTO() {
	FGamePlayerDTO gamePlayerDTO = FGamePlayerDTO(Points,Gold,FertilizerActive);
	for (ACard* card : Cards) {
		gamePlayerDTO.Cards.Add(card->GenerateDTO());
	}

	for (ATile* tile : Tiles) {
		gamePlayerDTO.Tiles.Add(tile->GenerateDTO());
	}
	return gamePlayerDTO;
}

FGamePlayerDTO AGamePlayer::GenerateMinimalDTO() {
	FGamePlayerDTO gamePlayerDTO = FGamePlayerDTO(Points, Gold, FertilizerActive);
	for (ACard* card : Cards) {
		gamePlayerDTO.Cards.Add(card->GenerateDTO());
	}

	for (ATile* tile : Tiles) {
		gamePlayerDTO.Tiles.Add(tile->GenerateMinimalDTO());
	}
	return gamePlayerDTO;
}

void AGamePlayer::EndPlayerInput()
{
//	try {
	if(Socket)
		Socket->EndInput();
//	}
//	catch (bool error) {
//		UE_LOG(LogTemp, Warning, TEXT("Error stopping input %b"), error);
//	}
}

AGamePlayer::~AGamePlayer()
{
	UE_LOG(LogTemp, Warning, TEXT("Game player deleted"));
}

int AGamePlayer::GetPoints()
{
	return Points;
}

int AGamePlayer::GetGold()
{
	return Gold;
}
int AGamePlayer::GetFertilizerActive()
{
	return FertilizerActive;
}

FString AGamePlayer::GetName()
{
	return Name;
}
