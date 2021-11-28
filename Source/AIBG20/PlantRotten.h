#pragma once

#include "CoreMinimal.h"
#include "PlantState.h"

class AIBG20_API PlantRotten : public PlantState
{
public:
	PlantRotten();
	~PlantRotten();

	void Harvest();
};
