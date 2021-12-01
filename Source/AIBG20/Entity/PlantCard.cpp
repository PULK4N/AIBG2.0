// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantCard.h"
#include "Plant.h"

// Sets default values
APlantCard::APlantCard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APlantCard::BeginPlay()
{
	Super::BeginPlay();
	
}

APlant* APlantCard::CreatePlant()
{
	return nullptr;
}

// Called every frame
void APlantCard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

