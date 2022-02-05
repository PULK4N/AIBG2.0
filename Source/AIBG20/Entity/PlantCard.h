// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Card.h"
#include "CoreMinimal.h"
#include "PlantCard.generated.h"

class APlant;

UCLASS()
class AIBG20_API APlantCard : public ACard
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantCard();
	FString Name;
	int HarvestPoints;
	int HavestIncome;
	int WaterNeeded;
	int DaysToRot;
};
