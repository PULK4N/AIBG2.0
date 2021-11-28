#pragma once

#include "CoreMinimal.h"
#include "PlantState.h"
#include "PlantReadyForHarvest.h"
#include "PlantRotten.h"
#include "PlantGrowing.h"

class AIBG20_API Plant
{
public:
	enum State
	{
		ST_GROWING,
		ST_READY_FOR_HARVEST,
		ST_ROTTEN
	};

	int harvestPoints;
	int harvestIncome;
	FString name;
	int currentHarvestPoints;
	int currentHarvestIncome;
	unsigned int waterNeeded;
	unsigned int daysToRot;

	Plant();
	virtual ~Plant();

	void setState(State state);

private:
	PlantState *currentState;
};
