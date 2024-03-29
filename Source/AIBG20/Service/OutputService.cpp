// Fill out your copyright notice in the Description page of Project Settings.


#include "OutputService.h"
#include "Json.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
#include "../GameMode/GameMap.h"
#include "../Entity/GamePlayer.h"
#include "../EntityDTO/DTO.h"
#include "../Defines.h"

// Sets default values
AOutputService::AOutputService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

AOutputService::~AOutputService() {
	UE_LOG(LogTemp, Warning, TEXT("AOutputService deleted"));
}

void AOutputService::SendOutput(AGameMap* gm, AGamePlayer* gp)
{
	FString Json;
	FGamePlayerDTO playerSource = gp->GenerateDTO();
	FGamePlayerDTO playerEnemy = gm->GetEnemyPlayer(gp)->GenerateMinimalDTO();
	TArray<FTileDTO> tiles = gm->GenerateMinimalDTO();
	FDTO output = FDTO(playerSource, playerEnemy, 10 - gm->getNumOfTurns() % RAIN_DAY);
	for (FTileDTO tile : tiles) {
		output.Tiles.Add(tile);
	}
	if (FJsonObjectConverter::UStructToJsonObjectString<FDTO>(output, Json)) {
		gp->SendOutput(Json);
	}
	else {
		throw "error";
	}
}


