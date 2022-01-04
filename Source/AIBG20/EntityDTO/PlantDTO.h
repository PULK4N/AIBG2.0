#pragma once
//

#include "PlantDTO.generated.h"

USTRUCT()
struct FPlantDTO
{
	GENERATED_BODY()

	UPROPERTY()
	int Id;

	UPROPERTY()
	int GoldWorth;

	UPROPERTY()
	int WaterNeeded;

	UPROPERTY()
	int DaysToRot;

	FPlantDTO(int id = 0, int goldWorth = 0, int waterNeeded = 0, int daysToRot = 0)
		: Id(id), GoldWorth(goldWorth), WaterNeeded(waterNeeded), DaysToRot(daysToRot){};
};