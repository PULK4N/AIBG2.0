#pragma once

#include "CoreMinimal.h"
#include "Plant.h"

class AIBG20_API PlantState
{
	virtual void Grow(Plant *plant);
	virtual void Rot(Plant *plant);
	virtual void Ready(Plant *plant);
};
