// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../EntityDto/PlantDTO.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plant.generated.h"

class UStaticMeshComponent;
class UStaticMesh;

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
public:	
	enum State
	{
		ST_GROWING,
		ST_READY_FOR_HARVEST,
		ST_ROTTEN
	};
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Water(int drops);
	int Harvest();
	void Rot();
	UPROPERTY(EditAnywhere, Category = "Properties")
	int DaysToRotCurrent;

	State PlantState;

	FPlantDTO GenerateDTO();
	FPlantDTO GenerateMinimalDTO();

protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Properties")
	int Id;

	UPROPERTY(EditAnywhere, Category = "Properties")
	int GoldWorth;

	UPROPERTY(EditAnywhere, Category = "Properties")
	int WaterNeeded;

	UPROPERTY(EditAnywhere, Category = "Properties")
	int DaysToRot;

	UPROPERTY(EditAnywhere)
	UStaticMesh* MeshRotten;

	UPROPERTY(EditAnywhere)
	UStaticMesh* MeshReady;
};
