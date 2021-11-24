#pragma once

#include "CoreMinimal.h"
#include "PlantState.h"

class AIBG20_API PlantGrowing : public PlantState
{
public:
	PlantGrowing();
	~PlantGrowing();

	void Ready(Plant *plant);
	void Rot(Plant *plant);
};
