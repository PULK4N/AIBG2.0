// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Command/BuyingLandActionCommand.h"
#include "../Command/WateringActionCommand.h"
#include "../Command/PlantingActionCommand.h"
#include "../Command/MoleCardActionCommand.h"
#include "../Command/HarvestingActionCommand.h"
#include "../Command/FertilizerCardActionCommand.h"
#include "../Command/BuyingActionCommand.h"
#include "EnemyAI.generated.h"

class AGamePlayer;
class AGameMap;
enum sequence{SHOP_PLANT_WATER_HARVEST,BUYLAND_SHOP_PLANT_WATER_HARVEST,SHOP_PLANT_WATER_FERTILIZER_HARVEST,BUYLAND_SHOP_PLANT_WATER_FERTILIZER_HARVEST, SHOP_FERTILIZER_FERTILIZER_PLANT_WATER_HARVEST, BUYLAND_SHOP_FERTILIZER_FERTILIZER_PLANT_WATER_HARVEST,NONE};
enum flower{ANEMONE,BLUE_JAZZ,CROCUS,TULIP};

UCLASS()
class AIBG20_API AEnemyAI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void ExecuteBotCommand();
//	bool IsGoingToRainOnTulip(sequence sq);
	void BuyLand(int num_of_owned_tiles);
	void BuyCard(int cardId, int amount);
	void PlaceFlowers(flower fl, int num_of_owned_tiles);
	void WaterFlowers(flower fl, int num_of_owned_tiles, bool Fertilizer);
	void ActivateFertilizer();
	void HarvestFlowers();

public:	
	AGameMap* GameMap;
	AGamePlayer* SourceGamePlayer;
	AGamePlayer* EnemyPlayer;
	int sequenceCounter;
	flower flowerToBuy;
	sequence currentSequence;
	sequence Evaluate();

//	UFUNCTION(BlueprintCallable)
};
