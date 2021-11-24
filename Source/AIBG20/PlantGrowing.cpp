#include "PlantGrowing.h"

PlantGrowing::PlantGrowing()
{
}

PlantGrowing::~PlantGrowing()
{
}

void PlantGrowing::Ready(Plant* plant)
{
	plant->setState(Plant::ST_READY_FOR_HARVEST);
}

void PlantGrowing::Rot(Plant* plant)
{
	plant->setState(Plant::ST_ROTTEN);
}