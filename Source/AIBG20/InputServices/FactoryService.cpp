#include "FactoryService.h"

FactoryService::FactoryService()
{
        
    wateringCommandFactory = new WateringCommandFactory();

    buyingCommandFactory = new BuyingCommandFactory();

    plantingCommandFactory = new PlantingCommandFactory();

    fertilizerCommandFactory = new FertilizerCommandFactory();
    
    moleCommandFactory = new MoleCommandFactory();

    harvestingCommandFactory = new HarvestingCommandFactory();

    buyingLandCommandFactory = new BuyingLandCommandFactory();
}

FactoryService::~FactoryService()
{
    delete wateringCommandFactory;
    
    delete buyingCommandFactory;
    
    delete plantingCommandFactory;
    
    delete fertilizerCommandFactory;
    
    delete moleCommandFactory;
    
    delete harvestingCommandFactory;
    
    delete buyingLandCommandFactory;
}

ActionCommandFactory* FactoryService::InputAction(FString action, AGamePlayer *player) {
    switch (action[0])
    {
    case 'W':
        return wateringCommandFactory; 
    case 'C':
        return buyingCommandFactory; 
    case 'P':
        return plantingCommandFactory; 
    case 'F':
        return fertilizerCommandFactory; 
    case 'M':
        return moleCommandFactory; 
    case 'H':
        return harvestingCommandFactory; 
    case 'L':
        return buyingLandCommandFactory;    
    default:
        return nullptr;
    }
}
