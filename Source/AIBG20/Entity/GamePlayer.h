// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Card.h"
#include "Tile.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GamePlayer.generated.h"

UCLASS()
class AIBG20_API AGamePlayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGamePlayer();

	UPROPERTY()
	int Points;
	UPROPERTY()
	int Gold;
	UPROPERTY()
	int WaterOwned;
	UPROPERTY()
	int MolesOwned;
	UPROPERTY()
	FString Name;
	ATile** Tiles;
	TArray<ACard> Cards;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void InstantiateTiles();
	void BuyCard(ACard& card);
	void BuyTile(int x, int y);
	void PlacePlant(int CardId, int x, int y);
	void WaterPlant(int amount, int x, int y);
	void HarvestPlants();
};
