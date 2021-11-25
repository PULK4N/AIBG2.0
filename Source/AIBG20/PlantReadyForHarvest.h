#pragma once

#include "CoreMinimal.h"
#include "PlantState.h"

class AIBG20_API PlantReadyForHarvest : public PlantState
{
public:
	PlantReadyForHarvest();
	~PlantReadyForHarvest();
	void Rot();
};
