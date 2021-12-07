// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"
#include "GameMap.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATile::ChangeMeshComponent(OWNER owner) {
	if (owner == PLAYER_1) {
		MeshComp->SetStaticMesh(Player1Mesh);
	}
	else {
		MeshComp->SetStaticMesh(Player2Mesh);
	}
}

