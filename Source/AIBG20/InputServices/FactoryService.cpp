#include "FactoryService.h"

FactoryService::FactoryService()
{
}

FactoryService::~FactoryService()
{
}

ActionCommandFactory* FactoryService::InputAction(FString action, AGamePlayer *player) {
    switch (action.at(0))
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
        break;
    }
}
