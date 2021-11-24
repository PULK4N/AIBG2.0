#include "PlantReadyForHarvest.h"

PlantReadyForHarvest::PlantReadyForHarvest()
{
}

PlantReadyForHarvest::~PlantReadyForHarvest()
{
}

void PlantReadyForHarvest::Rot(Plant* plant)
{
	plant->setState(Plant::ST_ROTTEN);
}