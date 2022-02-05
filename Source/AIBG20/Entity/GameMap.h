// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../EntityDTO/TileDTO.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameMap.generated.h"

class ATile;
class AGamePlayer;
class ASpawnService;
class AOutputService;

UCLASS()
class AIBG20_API AGameMap : public AActor
{
	GENERATED_BODY()
public:	
	AGameMap();
	~AGameMap();
	// Sets default values for this actor's properties

	TArray<TArray<ATile*>> Tiles;
	UPROPERTY(VisibleAnywhere, Category = "Players")
	AGamePlayer* Player1;
	UPROPERTY(VisibleAnywhere, Category = "Players")
	AGamePlayer* Player2;

	UPROPERTY(VisibleAnywhere)
	AGamePlayer* OnTheMovePlayer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASpawnService> SpawnServiceToSpawn;
	UPROPERTY(EditAnywhere)
	int turn;
	AOutputService* outputService;

	UFUNCTION(BlueprintImplementableEvent)
	void ShowWinner();
	UFUNCTION(BlueprintImplementableEvent)
	void StartRainAnimation();


public:	
	ATile* FindTile(int x, int y);
	int WhoOwnesTile(int x, int y);

	UFUNCTION(BlueprintCallable)
	int getNumOfTurns();

	void SwitchPlayers();
	void NextTurn();
	void Rain();
	void DecrementFertilizers();
	void RotPlants();
	AGamePlayer* GetEnemyPlayer(AGamePlayer* source);
//	void TestThread();
	TArray<FTileDTO> GenerateMinimalDTO();

};
