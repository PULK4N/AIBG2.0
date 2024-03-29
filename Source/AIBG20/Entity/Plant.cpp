// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"

// Sets default values
APlant::APlant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

APlant::~APlant()
{

}
// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlant::Water(int drops)
{
	WaterNeeded -= drops;
	if (WaterNeeded == 0)
	{
		Ready();
	}
	else if(WaterNeeded < 0)
	{
		Rot();
	}
}

int APlant::Harvest()
{
	return GoldWorth;
}

void APlant::Rot()
{
	PlantState = ST_ROTTEN;
	GoldWorth = 0;
	WaterNeeded = -1;
	MeshComp->SetStaticMesh(MeshRotten);
}

FPlantDTO APlant::GenerateDTO()
{
	return FPlantDTO(Id, GoldWorth, WaterNeeded, DaysToRot);
}

FPlantDTO APlant::GenerateMinimalDTO()
{
	return FPlantDTO(Id);
}

void APlant::Ready()
{
	PlantState = ST_READY_FOR_HARVEST;
	MeshComp->SetStaticMesh(MeshReady);
}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}