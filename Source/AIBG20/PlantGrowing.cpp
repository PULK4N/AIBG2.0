#include "PlantGrowing.h"

PlantGrowing::PlantGrowing()
{
}

PlantGrowing::~PlantGrowing()
{
}

void PlantGrowing::Ready()
{
	plant->setState(Plant::ST_READY_FOR_HARVEST);
}

void PlantGrowing::Rot()
{
	plant->setState(Plant::ST_ROTTEN);
}

void PlantGrowing::Water(int drops)
{
	if (plant->waterNeeded - drops <= 0)
	{
		plant->waterNeeded = 0;
		this->Ready();
	}
	else 
	{
		plant->waterNeeded -= drops;
	}
}