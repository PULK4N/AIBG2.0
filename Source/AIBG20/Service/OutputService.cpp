// Fill out your copyright notice in the Description page of Project Settings.


#include "OutputService.h"
#include "../Entity/GameMap.h"
#include "../Entity/GamePlayer.h"

// Sets default values
AOutputService::AOutputService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int** AOutputService::generateMap(AGameMap* gm)
{
	int** map = new int* [8];
	for (int i = 0; i < 8; ++i)
	{
		map[i] = new int[8];

		for (int j = 0; j < 8; ++j)
		{
			map[i][j] = gm->WhoOwnesTile(i, j);
		}
	}
	return map;
}

void AOutputService::setParams(AGameMap* gm, AGamePlayer* gp)
{
	//PlayerSource = gp;
	//TileMap = generateMap(gm);
	//gold = gp->Gold;
	//points = gp->Points;
	//fertilizerActive = gp->fertilizerActive;
	//bRainedThisTurn = gm->turn % 10;
	//for (ACard* c : gp->Cards) {
	//	cards.insert(make_pair(c->id, c->owned));
	//}
}

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

