#pragma once

#include "CoreMinimal.h"
#include "Plant.h"

class AIBG20_API PlantState
{
public:
	Plant* plant;

	virtual void Water(int drops);
	virtual void Harvest();
	virtual void Rot();
	virtual void Ready();
};
