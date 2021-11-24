#include "Plant.h"

Plant::Plant()
{
}

Plant::~Plant()
{
}

void Plant::setState(State state)
{
	delete currentState;

	if (state == ST_GROWING)
	{
		currentState = new PlantGrowing();
	}
	else if (state == ST_READY_FOR_HARVEST)
	{
		currentState = new PlantReadyForHarvest();
	}
	else
	{
		currentState = new PlantRotten();
	}
}