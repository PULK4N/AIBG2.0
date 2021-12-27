#include "FactoryService.h"
#include "../Factory/WateringCommandFactory.h"
#include "../Factory/BuyingCommandFactory.h"
#include "../Factory/PlantingCommandFactory.h"
#include "../Factory/FertilizerCommandFactory.h"
#include "../Factory/MoleCommandFactory.h"
#include "../Factory/BuyingCommandFactory.h"
#include "../Factory/HarvestingCommandFactory.h"
#include "../Factory/BuyingLandCommandFactory.h"

FactoryService::FactoryService()
{
}

FactoryService::~FactoryService()
{
}

ActionCommandFactory* FactoryService::InputAction(FString action, AGamePlayer *player) {
    switch (action[0])
    {
    case 'W':
        return new WateringCommandFactory(); 
    case 'C':
        return new BuyingCommandFactory(); 
    case 'P':
        return new PlantingCommandFactory(); 
    case 'F':
        return new FertilizerCommandFactory(); 
    case 'M':
        return new MoleCommandFactory(); 
    case 'H':
        return new HarvestingCommandFactory(); 
    case 'L':
        return new BuyingLandCommandFactory();    
    default:
        return nullptr;
    }
}
