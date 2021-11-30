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

}

void APlant::Harvest()
{

}

void APlant::Rot()
{
	PlantState = ST_ROTTEN;
}

void APlant::Ready()
{

}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


//void APlant::setState(State state)
//{
//	delete currentState;
//
//	if (state == ST_GROWING)
//	{
//		currentState = new PlantGrowing();
//	}
//	else if (state == ST_READY_FOR_HARVEST)
//	{
//		currentState = new PlantReadyForHarvest();
//	}
//	else
//	{
//		currentState = new PlantRotten();
//	}
//}

//void PlantGrowing::Ready()
//{
//	plant->setState(Plant::ST_READY_FOR_HARVEST);
//}
//
//void PlantGrowing::Rot()
//{
//	plant->setState(Plant::ST_ROTTEN);
//}
//
//void PlantGrowing::Water(int drops)
//{
//	if (plant->waterNeeded - drops <= 0)
//	{
//		plant->waterNeeded = 0;
//		this->Ready();
//	}
//	else
//	{
//		plant->waterNeeded -= drops;
//	}
//}