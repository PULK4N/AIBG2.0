// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayer.h"

// Sets default values
AGamePlayer::AGamePlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AGamePlayer::InstantiateTiles() {
	Tiles = new ATile * [8];
	for (int i = 0; i < 8; ++i)
		Tiles[i] = new ATile[8];
}

void AGamePlayer::BuyCard(ACard& card)
{
}

void AGamePlayer::BuyTile(int x, int y)
{
}

void AGamePlayer::PlacePlant(int CardId, int x, int y)
{
}

void AGamePlayer::WaterPlant(int amount, int x, int y)
{
}

void AGamePlayer::HarvestPlants()
{
}

// Called when the game starts or when spawned
void AGamePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGamePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
