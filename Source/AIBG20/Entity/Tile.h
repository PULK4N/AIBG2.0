// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Plant.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UStaticMeshComponent;
class AGamePlayer;

UCLASS()
class AIBG20_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	enum OWNER {
		PLAYER_1,
		PLAYER_2
	};
	UPROPERTY(VisibleAnywhere)
	bool bIsPlanted;
	UPROPERTY(VisibleAnywhere)
	APlant* Plant;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
	class UStaticMesh* Player1Mesh;

	UPROPERTY(EditAnywhere)
	class UStaticMesh* Player2Mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ChangeMeshComponent(OWNER owner);
};
