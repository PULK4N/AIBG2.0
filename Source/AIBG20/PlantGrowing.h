#pragma once

#include "CoreMinimal.h"
#include "PlantState.h"

class AIBG20_API PlantGrowing : public PlantState
{
public:
	PlantGrowing();
	~PlantGrowing();

	void Ready();
	void Rot();
	void Water(int drops);
};
