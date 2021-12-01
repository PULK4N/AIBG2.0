// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMap.h"

void AGameMap::InstantiateTiles() {
	Tiles = new ATile * [8];
	for (int i = 0; i < 8; ++i)
		Tiles[i] = new ATile[8];
}

// Sets default values
AGameMap::AGameMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AGameMap::BeginPlay()
{
	Super::BeginPlay();
	InstantiateTiles();
}

// Called every frame
void AGameMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

