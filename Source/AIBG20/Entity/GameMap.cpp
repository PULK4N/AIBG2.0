// Fill out your copyright notice in the Description page of Project Settings.

#include "GameMap.h"
#include "GamePlayer.h"
#include "../Server/TCPSocket.h"
#include "Tile.h"
#include "../Command/BuyingActionCommand.h"
#include "../Command/BuyingLandActionCommand.h"
#include "../Command/FertilizerCardActionCommand.h"
#include "../Command/MoleCardActionCommand.h"
#include "../Command/HarvestingActionCommand.h"
#include "../Command/WateringActionCommand.h"
#include "../Command/PlantingActionCommand.h"
#include "./PlantCards/TestPlantCard.h"
#include "../Defines.h"


// Sets default values
AGameMap::AGameMap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AGameMap::InstantiateTiles() {
	for (int i = 0; i < 8; ++i) {
		Tiles.Add(TArray<ATile*>());
		for (int j = 0; j < 8; ++j) {
			Tiles[i].Add(SpawnTiles(i, j));
		}
	}
}

ATile* AGameMap::SpawnTiles(int x, int y) {
	FActorSpawnParameters Spawnparams;
	FVector location = FVector(-306.0 - x * 49, -425.0 + y * 49, 389.0);
	FRotator rotation = FRotator(0, 0, 90);
	if (GetWorld()) {
		ATile* SpawnedActorRef = GetWorld()->SpawnActor<ATile>(TileToSpawn, location, rotation, Spawnparams);
		if (x == 0 && y == 0) {
			SpawnedActorRef->ChangeMeshComponent(ATile::PLAYER_1);
			Player1->Tiles.Add(SpawnedActorRef);
		}
		else if (x == 7 && y == 7) {
			SpawnedActorRef->ChangeMeshComponent(ATile::PLAYER_2);
			Player2->Tiles.Add(SpawnedActorRef);
		}
		return SpawnedActorRef;
	}
	return nullptr;
}

// Called when the game starts or when spawned
void AGameMap::BeginPlay()
{
	Super::BeginPlay();
	ActionCommand::SetGameMapInstance(this);
	InstantiatePlayers();
	InstantiateTiles();
	Test();//Remove when game starts
}

// Called every frame
void AGameMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ATile* AGameMap::FindTile(int x, int y)
{
	return Tiles[x][y];
}

void AGameMap::InstantiatePlayers() {
	FActorSpawnParameters Spawnparams;
	FVector location = FVector(0, 0, 0);
	FRotator rotation = FRotator(0, 0, 0);
	Player1 = GetWorld()->SpawnActor<AGamePlayer>(GamePlayerActorToSpawn, location, rotation, Spawnparams);
	Player2 = GetWorld()->SpawnActor<AGamePlayer>(GamePlayerActorToSpawn, location, rotation, Spawnparams);
	Player1->InstantiateSocket("8081");
	Player2->InstantiateSocket("8082");
}

void AGameMap::Test() {
	Player2->BuyTile(Tiles[6][7]);

	Player1->FindCardById(MOLE_CARD_ID)->Owned = 1;
	Player1->FindCardById(FERTILIZER_CARD_ID)->Owned = 2;
	Player1->FindCardById(WATER_CARD_ID)->Owned = 6;
	Player1->FindCardById(TESTPLANT_CARD_ID)->Owned = 1;

	MoleCardActionCommand* mole = new MoleCardActionCommand();
	mole->Player = Player1;
	mole->CoordinationX = 7;
	mole->CoordinationY = 7;
	mole->Execute();
	mole->CoordinationX = 6;
	mole->CoordinationY = 6;
	mole->Execute();
	mole->CoordinationX = 6;
	mole->CoordinationY = 7;
	mole->Execute();
	mole->~MoleCardActionCommand();

	HarvestingActionCommand* harvestingCommand = new HarvestingActionCommand();
	harvestingCommand->Player = Player1;
	harvestingCommand->Execute();
	harvestingCommand->~HarvestingActionCommand();

	FertilizerCardActionCommand* fertilizerCommand = new FertilizerCardActionCommand();
	fertilizerCommand->Player = Player1;
	fertilizerCommand->Execute();
	fertilizerCommand->Execute();
	fertilizerCommand->Execute();
	fertilizerCommand->~FertilizerCardActionCommand();

	PlantingActionCommand* plantingCommand = new PlantingActionCommand();
	plantingCommand->Player = Player1;
	plantingCommand->Card = GetWorld()->SpawnActor<ATestPlantCard>(ATestPlantCard::StaticClass());
	plantingCommand->CoordinationX = 0;
	plantingCommand->CoordinationY = 0;
	plantingCommand->Execute();
	plantingCommand->Execute();
	plantingCommand->Execute();
	plantingCommand->~PlantingActionCommand();

}
