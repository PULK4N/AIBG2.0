// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GamePlayer.h"
#include "Tile.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameMap.generated.h"

UCLASS()
class AIBG20_API AGameMap : public AActor
{
	GENERATED_BODY()
private:
	void InstantiateTiles();
	
public:	
	// Sets default values for this actor's properties
	AGameMap();
	//TArray<TArray<ATile>> Tiles;
	ATile** Tiles;
	AGamePlayer* Player1;
	AGamePlayer* Player2;
	int DaysUntillRain;
	AGamePlayer* OnTheMovePlayer;
	int NumOfTurns;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
