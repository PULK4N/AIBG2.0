#include "PlantReadyForHarvest.h"

PlantReadyForHarvest::PlantReadyForHarvest()
{
}

PlantReadyForHarvest::~PlantReadyForHarvest()
{
}

void PlantReadyForHarvest::Rot()
{
	plant->setState(Plant::ST_ROTTEN);
}