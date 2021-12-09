// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Card.h"
#include "Tile.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GamePlayer.generated.h"


class ATCPSocket;
class InputService;

UCLASS()
class AIBG20_API AGamePlayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGamePlayer();

	enum CARD_INDEX {
		WATER,
		FERTILIZER,
		MOLE
	};

	UPROPERTY(EditAnywhere)
		int Points;
	UPROPERTY(EditAnywhere)
		int Gold;
	UPROPERTY()
	FString Name;
	TArray<ATile*> Tiles;
	TArray<ACard*> Cards;
	ATCPSocket* Socket;
	InputService* inputService;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ATCPSocket> TcpSocketActorToSpawn;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void BuyCard(ACard* card);
	void BuyTile(int x, int y, ATile* tile);
	void PlacePlant(int CardId, int x, int y);
	void WaterPlant(ATile* tile);
	void HarvestPlants();
	void AddFertilizer();
	void InstantiateSocket(FString port);
	ACard* FindCardById(int id);
};
