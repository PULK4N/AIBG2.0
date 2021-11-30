// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantCard.generated.h"
#include "Card.h"

UCLASS()
class AIBG20_API APlantCard : public ACard
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantCard();
	int HarvestPoints;
	int HavestIncome;
	int WaterNeeded;
	int DaysToRot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
