// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnService.h"
#include "../Defines.h"

// Sets default values
ASpawnService::ASpawnService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ASpawnService::Instantiate(AGameMap* _gameMap) {
	this->gameMap = _gameMap;

	switch (_gameMap->gamemode) {
	case EGameMode::AI_VS_AI:
		InstantiateAiVsAi();
		break;
	case EGameMode::AI_VS_GAME:
		InstantiateAiVsGame();
		break;
	case EGameMode::PLAYER_VS_GAME:
		InstantiatePlayerVsGame();
		break;
	}
}


void ASpawnService::InstantiateAiVsAi()
{
	ActionCommand::SetGameMapInstance(gameMap);
	InstantiateAiVsAiPlayers();
	InputService::getInstance(gameMap);
	InstantiateTiles();
}

void ASpawnService::InstantiateAiVsGame()
{
	ActionCommand::SetGameMapInstance(gameMap);
	InstantiateAiVsGamePlayers();
	InputService::getInstance(gameMap);
	InstantiateTiles();
}

void ASpawnService::InstantiatePlayerVsGame()
{
	ActionCommand::SetGameMapInstance(gameMap);
	InstantiatePlayerVsGamePlayers();
	InputService::getInstance(gameMap);
	InstantiateTiles();
}

void ASpawnService::EndPlay(EEndPlayReason::Type reason) {
//	Super::EndPlay(EEndPlayReason::Type reason);
	InputService* inputService = InputService::getInstance(nullptr);
	if(inputService)
		delete inputService;
}

void ASpawnService::InstantiateTiles() {
	TSet<int> randomTileNumbers;
	for (int i = 0; i < 7; i++) {
		int randNum = rand() % 32;
		randomTileNumbers.Add(randNum);//brojevi sa jedne strane
		randomTileNumbers.Add(63 - randNum);
	}
		
	for (int i = 0; i < 8; i++) {
		gameMap->Tiles.Add(TArray<ATile*>());
		for (int j = 0; j < 8; j++) {
			bool startTile = i == 0 && j == 0 || i==7 && j==7;
			bool isSpecial = randomTileNumbers.Contains(i*8 + j) 
				&& !startTile;
			gameMap->Tiles[i].Add(SpawnTiles(i, j, isSpecial));
		}
	}
}

ATile* ASpawnService::SpawnTiles(int x, int y, bool bIsSpecial) {
	FActorSpawnParameters Spawnparams;
	FVector location = FVector(-400 - x * 49, -230.0 + y * 49, 448.0);
	FRotator rotation = FRotator(0, 0, 0);
	if (gameMap->GetWorld()) {
		ATile* SpawnedActorRef;
		if (bIsSpecial) {
			SpawnedActorRef = gameMap->GetWorld()->SpawnActor<ATile>(SpecialTileToSpawn, location, rotation, Spawnparams);
		}
		else {
			SpawnedActorRef = gameMap->GetWorld()->SpawnActor<ATile>(TileToSpawn, location, rotation, Spawnparams);
		}
		if (x == 0 && y == 0) {
			SpawnedActorRef->ChangeMeshComponent(ATile::PLAYER_1);
			gameMap->Player1->Tiles.Add(SpawnedActorRef);
		}
		else if (x == 7 && y == 7) {
			SpawnedActorRef->ChangeMeshComponent(ATile::PLAYER_2);
			gameMap->Player2->Tiles.Add(SpawnedActorRef);
		}
		SpawnedActorRef->X = x;
		SpawnedActorRef->Y = y;
		return SpawnedActorRef;
	}
	return nullptr;
}

void ASpawnService::InstantiateAiVsAiPlayers() {
	FActorSpawnParameters Spawnparams;
	FVector location = FVector(0, 0, 0);
	FRotator rotation = FRotator(0, 0, 0);
	gameMap->Player1 = GetWorld()->SpawnActor<AGamePlayer>(GamePlayerActorToSpawn, location, rotation, Spawnparams);
	gameMap->Player2 = GetWorld()->SpawnActor<AGamePlayer>(GamePlayerActorToSpawn, location, rotation, Spawnparams);
	gameMap->Player1->InstantiateSocket("8081");
	gameMap->Player2->InstantiateSocket("8082");
}

void ASpawnService::InstantiateAiVsGamePlayers() {
	FActorSpawnParameters Spawnparams;
	FVector location = FVector(0, 0, 0);
	FRotator rotation = FRotator(0, 0, 0);
	gameMap->Player1 = GetWorld()->SpawnActor<AGamePlayer>(GamePlayerActorToSpawn, location, rotation, Spawnparams);
	gameMap->Player2 = GetWorld()->SpawnActor<AGamePlayer>(GamePlayerActorToSpawn, location, rotation, Spawnparams);
	gameMap->Player1->InstantiateSocket("8081");

	AEnemyAI* enemyAI = GetWorld()->SpawnActor<AEnemyAI>(EnemyAiToSpawn, location, rotation, Spawnparams);
	gameMap->Player2->Name = "Bot";
	enemyAI->SourceGamePlayer = gameMap->Player2;
	enemyAI->EnemyPlayer = gameMap->Player1;
	enemyAI->GameMap = gameMap;
}

void ASpawnService::InstantiatePlayerVsGamePlayers() {
	FActorSpawnParameters Spawnparams;
	FVector location = FVector(0, 0, 0);
	FRotator rotation = FRotator(0, 0, 0);
	gameMap->Player1 = GetWorld()->SpawnActor<AGamePlayer>(GamePlayerActorToSpawn, location, rotation, Spawnparams);
	gameMap->Player2 = GetWorld()->SpawnActor<AGamePlayer>(GamePlayerActorToSpawn, location, rotation, Spawnparams);

	AEnemyAI* enemyAI = GetWorld()->SpawnActor<AEnemyAI>(EnemyAiToSpawn, location, rotation, Spawnparams);
	gameMap->Player2->Name = "Bot";
	enemyAI->SourceGamePlayer = gameMap->Player2;
	enemyAI->EnemyPlayer = gameMap->Player1;
	enemyAI->GameMap = gameMap;

	
}

