#include "ActionService.h"
#include "../Factory/ActionCommandFactory.h"
#include "../Factory/WateringCommandFactory.h"
#include "../Factory/BuyingCommandFactory.h"
#include "../Factory/PlantingCommandFactory.h"
#include "../Factory/FertilizerCommandFactory.h"
#include "../Factory/MoleCommandFactory.h"
#include "../Factory/BuyingCommandFactory.h"
#include "../Factory/HarvestingCommandFactory.h"
#include "../Factory/BuyingLandCommandFactory.h"

ActionService::ActionService()
{
}

ActionService::~ActionService()
{
    UE_LOG(LogTemp, Warning, TEXT("ActionService deleted"));
}

void ActionService::ExecuteActions(TArray<ActionCommand*> actionCommands, AGamePlayer* player) {
    for (ActionCommand* ac:actionCommands)
        ac->Execute();
    //for (ActionCommand* ac : actionCommands)
    //    delete ac;
    DeleteActions(actionCommands);
}

void ActionService::DeleteActions(TArray<ActionCommand*> actionCommands)
{
    if (actionCommands.Num() == 0)
        return;
    if (dynamic_cast<BuyingActionCommand*>(actionCommands[0]) != nullptr) {
        deleteBuyingActionCommands(actionCommands);
        return;
    }
    else if (dynamic_cast<BuyingLandActionCommand*>(actionCommands[0]) != nullptr) {
        deleteBuyingLandActionCommands(actionCommands);
        return;
    }
    else if (dynamic_cast<FertilizerCardActionCommand*>(actionCommands[0]) != nullptr) {
        deleteFertilizerCardActionCommands(actionCommands);
        return;
    }
    else if (dynamic_cast<HarvestingActionCommand*>(actionCommands[0]) != nullptr) {
        deleteHarvestingActionCommands(actionCommands);
        return;
    }
    else if (dynamic_cast<MoleCardActionCommand*>(actionCommands[0]) != nullptr) {
        deleteMoleCardActionCommands(actionCommands);
        return;
    }
    else if (dynamic_cast<PlantingActionCommand*>(actionCommands[0]) != nullptr) {
        deletePlantingActionCommands(actionCommands);
        return;
    }
    else if (dynamic_cast<WateringActionCommand*>(actionCommands[0]) != nullptr) {
        deleteWateringActionCommands(actionCommands);
        return;
    }
}

void ActionService::deleteBuyingActionCommands(TArray<ActionCommand*> actionCommands)
{
    for (ActionCommand* ac : actionCommands) {
        BuyingActionCommand* delActionCommand = dynamic_cast<BuyingActionCommand*>(ac);
        delete delActionCommand;
    }
}

void ActionService::deleteFertilizerCardActionCommands(TArray<ActionCommand*> actionCommands)
{
    for (ActionCommand* ac : actionCommands) {
        FertilizerCardActionCommand* delActionCommand = dynamic_cast<FertilizerCardActionCommand*>(ac);
        delete delActionCommand;
    }
}

void ActionService::deleteHarvestingActionCommands(TArray<ActionCommand*> actionCommands)
{
    for (ActionCommand* ac : actionCommands) {
        HarvestingActionCommand* delActionCommand = dynamic_cast<HarvestingActionCommand*>(ac);
        delete delActionCommand;
    }
}

void ActionService::deleteMoleCardActionCommands(TArray<ActionCommand*> actionCommands)
{
    for (ActionCommand* ac : actionCommands) {
        MoleCardActionCommand* delActionCommand = dynamic_cast<MoleCardActionCommand*>(ac);
        delete delActionCommand;
    }
}

void ActionService::deletePlantingActionCommands(TArray<ActionCommand*> actionCommands)
{
    for (ActionCommand* ac : actionCommands) {
        PlantingActionCommand* delActionCommand = dynamic_cast<PlantingActionCommand*>(ac);
        delete delActionCommand;
    }
}

void ActionService::deleteWateringActionCommands(TArray<ActionCommand*> actionCommands)
{
    for (ActionCommand* ac : actionCommands) {
        WateringActionCommand* delActionCommand = dynamic_cast<WateringActionCommand*>(ac);
        delete delActionCommand;
    }
}

void ActionService::deleteBuyingLandActionCommands(TArray<ActionCommand*> actionCommands)
{
    for (ActionCommand* ac : actionCommands) {
        BuyingLandActionCommand* delActionCommand = dynamic_cast<BuyingLandActionCommand*>(ac);
        delete delActionCommand;
    }
}
