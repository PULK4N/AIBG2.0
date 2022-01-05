// Fill out your copyright notice in the Description page of Project Settings.


#include "OutputService.h"
#include "Json.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
#include "../Entity/GameMap.h"
#include "../Entity/GamePlayer.h"
#include "../EntityDTO/DTO.h"

// Sets default values
AOutputService::AOutputService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

//int** AOutputService::generateMap(AGameMap* gm)
//{
//	int** map = new int* [8];
//	for (int i = 0; i < 8; ++i)
//	{
//		map[i] = new int[8];
//
//		for (int j = 0; j < 8; ++j)
//		{
//			map[i][j] = gm->WhoOwnesTile(i, j);
//		}
//	}
//	return map;
//}

void AOutputService::SendOutput(AGameMap* gm, AGamePlayer* gp)
{
	FString Json;
	FGamePlayerDTO playerSource = gp->GenerateDTO();
	FGamePlayerDTO playerEnemy = gm->GetEnemyPlayer(gp)->GenerateMinimalDTO();
	if (FJsonObjectConverter::UStructToJsonObjectString<FDTO>(FDTO(playerSource,
		playerEnemy, gm->DaysUntillRain % 10), Json)) {
		gp->SendOutput(Json);
	}
	else {
		throw "error";
	}
}//L;[0,1]

// Called when the game starts or when spawned
void AOutputService::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOutputService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

