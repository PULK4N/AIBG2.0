#pragma once

#include "PlantDTO.h"
#include "TileDTO.generated.h"

USTRUCT()
struct FTileDTO
{
	GENERATED_BODY()

	UPROPERTY()
	int X;
	UPROPERTY()
	int Y;
	UPROPERTY()
	bool bIsPlanted;
	UPROPERTY()
	bool bIsSpecial;
	UPROPERTY()
	FPlantDTO PlantDTO;

	FTileDTO(int x = 0, int y = 0, bool bisPlanted = false, bool bisSpecial = false, FPlantDTO plantDTO = FPlantDTO())
		: X(x), Y(y), bIsPlanted(bisPlanted), bIsSpecial(bisSpecial), PlantDTO(plantDTO){};

};
