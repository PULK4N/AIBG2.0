// Fill out your copyright notice in the Description page of Project Settings.

#include "GameMap.h"
#include "GamePlayer.h"
#include "../Server/TCPSocket.h"
#include "Tile.h"

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

// Sets default values
AGameMap::AGameMap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//if (Instance == nullptr) {
	//	Instance = this;
	//}
}

//AGameMap* AGameMap::GetInstance()
//{
//	return nullptr;// Instance;
//}

// Called when the game starts or when spawned
void AGameMap::BeginPlay()
{
	Super::BeginPlay();
	InstantiatePlayers();
	InstantiateTiles();
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