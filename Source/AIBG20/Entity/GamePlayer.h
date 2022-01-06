// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Card.h"
#include "Tile.h"
#include "../EntityDTO/GamePlayerDTO.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GamePlayer.generated.h"


class ATCPSocket;
class InputService;
class APlantService;

UCLASS()
class AIBG20_API AGamePlayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGamePlayer();
	~AGamePlayer();

	UPROPERTY(EditAnywhere, Category = "Points")
	int Points;
	UPROPERTY(EditAnywhere, Category = "Gold")
	int Gold;
	UPROPERTY(EditAnywhere, Category = "FertilizerActive")
	int FertilizerActive;
	UPROPERTY(BlueprintReadOnly, Category = "Name")
	FString Name;
	
	UFUNCTION(BlueprintPure, Category = "Points")
	int GetPoints();
	UFUNCTION(BlueprintPure, Category = "Gold")
	int GetGold();
	UFUNCTION(BlueprintPure, Category = "FertilizerActive")
	int GetFertilizerActive();
	UFUNCTION(BlueprintPure, Category = "Name")
	FString GetName();

	UPROPERTY(VisibleAnywhere)
	TArray<ATile*> Tiles;
	UPROPERTY(EditAnywhere)
	TArray<ACard*> Cards;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void AddCards();

	ATCPSocket* Socket;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ATCPSocket> TcpSocketActorToSpawn;
	UPROPERTY(EditAnywhere)
	TSubclassOf<APlantService> plantServiceToSpawn;
	UPROPERTY()
	APlantService* plantService;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void BuyCard(int id, int amount);
	void BuyTile(ATile* tile);
	void PlacePlant(int cardId, int x, int y, ATile* tile);
	void WaterPlant(int drops, ATile* tile);
	void HarvestPlants();
	void AddFertilizer();
	void DecrementFertilizer();
	void InstantiateSocket(FString port);
	void SendOutput(FString outputMessage);
	ACard* FindCardById(int id);
	FGamePlayerDTO GenerateDTO();
	FGamePlayerDTO GenerateMinimalDTO();
	void EndPlayerInput();
};
