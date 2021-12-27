// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameMap.generated.h"

class ATile;
class AGamePlayer;

UCLASS()
class AIBG20_API AGameMap : public AActor
{
	GENERATED_BODY()
//	static AGameMap* Instance;
public:	
//	static AGameMap* GetInstance();
	AGameMap();
	// Sets default values for this actor's properties

	TArray<TArray<ATile*>> Tiles;
	AGamePlayer* Player1;
	AGamePlayer* Player2;

	int DaysUntillRain;
	AGamePlayer* OnTheMovePlayer;
	int NumOfTurns;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ATile> TileToSpawn;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AGamePlayer> GamePlayerActorToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	ATile* FindTile(int x, int y);
//	void TestThread();
private:
	void InstantiatePlayers();
	void InstantiateTiles();
	ATile* SpawnTiles(int x, int y);
	void Test();
};
