// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plant.generated.h"


UCLASS()
class AIBG20_API APlant : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlant();
	~APlant();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Ready();
	enum State
	{
		ST_GROWING,
		ST_READY_FOR_HARVEST,
		ST_ROTTEN
	};
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Water(int drops);
	void Harvest();
	void Rot();

	State PlantState;
	int harvestPoints;
	int harvestIncome;
	FString name;
	int currentHarvestPoints;
	int currentHarvestIncome;
	unsigned int waterNeeded;
	unsigned int daysToRot;

//	void setState(State state);
};
