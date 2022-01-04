// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../Command/ActionCommand.h"
#include "../Entity/GameMap.h"
#include "../Entity/Tile.h"
#include "../Entity/SpecialTile.h"
#include "../InputServices/InputService.h"
#include "../Server/TCPSocket.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnService.generated.h"

UCLASS()
class AIBG20_API ASpawnService : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnService();
	void Instantiate(AGameMap* gameMap);
protected:
	AGameMap* gameMap;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ATile> TileToSpawn;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ATile> SpecialTileToSpawn;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AGamePlayer> GamePlayerActorToSpawn;

	virtual void EndPlay(EEndPlayReason::Type reason) override;
	void InstantiatePlayers();
	void InstantiateTiles();
	ATile* SpawnTiles(int x, int y, bool bIsSpecial);

};
