#include "FactoryService.h"
#include "../InputDTO/ActionDTO.h"
#include "Json.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

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

    UE_LOG(LogTemp, Warning, TEXT("FactoryService deleted"));
}

ActionCommandFactory* FactoryService::InputAction(FString action, AGamePlayer *player) {
    
    FActionDTO actionDto;
    bool converted = FJsonObjectConverter::JsonObjectStringToUStruct(action, &actionDto, 0, 0);
    UE_LOG(LogTemp, Warning, TEXT("%s"), converted ? "True" : "False");

    if (actionDto.ActionType.IsEmpty() == false) {
        switch (actionDto.ActionType[0])
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
    return nullptr;
}
