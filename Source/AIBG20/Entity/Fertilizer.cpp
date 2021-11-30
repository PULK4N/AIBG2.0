// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/Fertilizer.h"

// Sets default values
AFertilizer::AFertilizer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFertilizer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFertilizer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

