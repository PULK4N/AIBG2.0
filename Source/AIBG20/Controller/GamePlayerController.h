// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Entity/Gameplayer.h"
#include "../Entity/Tile.h"
#include "../Entity/Card.h"
#include "../Entity/PlantCard.h"
#include "../Command/BuyingLandActionCommand.h"
#include "../Command/WateringActionCommand.h"
#include "../Command/PlantingActionCommand.h"
#include "../Command/MoleCardActionCommand.h"
#include "../Command/HarvestingActionCommand.h"
#include "../Command/FertilizerCardActionCommand.h"
#include "../Command/BuyingActionCommand.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

UENUM(BlueprintType)
enum class EActions : uint8 {
	SHOP UMETA(DisplayName = "SHOP"),
	BUY_LAND UMETA(DisplayName = "BUY_LAND"),
	FERTILIZER UMETA(DisplayName = "FERTILIZER"),
	MOLE UMETA(DisplayName = "MOLE"),
	HARVEST UMETA(DisplayName = "HARVEST"),
	PLANT UMETA(DisplayName = "PLANT"),
	WATER UMETA(DisplayName = "WATER"),
	NONE UMETA(DisplayName = "NONE"),
};
/**
 * 
 */
UCLASS()
class AIBG20_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable)
	void ExecuteAction(AGamePlayer* currentPlayer, ATile* currentTile, int cardId,EActions currentAction);
};
