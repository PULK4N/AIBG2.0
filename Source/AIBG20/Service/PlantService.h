// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantService.generated.h"

class APlant;

UCLASS()
class AIBG20_API APlantService : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantService();
	~APlantService();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APlant> AnemoneFlower;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APlant> BlueJazz;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APlant> CrocusFlower;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APlant> Tulip;

public:	
	APlant* SpawnPlant(int plantCardId, int x, int y);
	virtual void Tick(float DeltaTime) override;

};
