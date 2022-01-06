// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"
#include "GameMap.h"
#include "SpecialTile.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	bIsPlanted = false;
}


void ATile::ChangeMeshComponent(OWNER owner) {
	if (owner == PLAYER_1) {
		MeshComp->SetStaticMesh(Player1Mesh);
	}
	else {
		MeshComp->SetStaticMesh(Player2Mesh);
	}
	//if (MeshComp->GetStaticMesh() == Player1Mesh)
	//	MeshComp->SetStaticMesh(Player2Mesh);
	//else
	//	MeshComp->SetStaticMesh(Player1Mesh);
}

FTileDTO ATile::GenerateDTO() {
	if(bIsPlanted)
		return FTileDTO(X,Y, bIsPlanted, (Cast<ASpecialTile>(this) != nullptr), Plant->GenerateDTO());
	else
		return FTileDTO(X, Y, bIsPlanted, (Cast<ASpecialTile>(this) != nullptr), FPlantDTO());
}

FTileDTO ATile::GenerateMinimalDTO() {
	if (bIsPlanted)
		return FTileDTO(X, Y, bIsPlanted, (Cast<ASpecialTile>(this) != nullptr), Plant->GenerateMinimalDTO());
	else
		return FTileDTO(X, Y, bIsPlanted, (Cast<ASpecialTile>(this) != nullptr), FPlantDTO());
}