// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../Command/ActionCommand.h"

class AIBG20_API ActionService
{
public:
    ActionService();
    ~ActionService();

    void ExecuteActions(TArray<ActionCommand*> actionCommands, AGamePlayer*player);

private:
    void DeleteActions(TArray<ActionCommand*> actionCommands);
    void deleteBuyingLandActionCommands(TArray<ActionCommand*> actionCommands);
    void deleteBuyingActionCommands(TArray<ActionCommand*> actionCommands);
    void deleteFertilizerCardActionCommands(TArray<ActionCommand*> actionCommands);
    void deleteHarvestingActionCommands(TArray<ActionCommand*> actionCommands);
    void deleteMoleCardActionCommands(TArray<ActionCommand*> actionCommands);
    void deletePlantingActionCommands(TArray<ActionCommand*> actionCommands);
    void deleteWateringActionCommands(TArray<ActionCommand*> actionCommands);
};