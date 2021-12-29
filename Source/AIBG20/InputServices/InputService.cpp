#include "InputService.h"
#include "../Entity/GameMap.h"
#include "ActionService.h"
#include "FactoryService.h"
#include "TimerService.h"
#include "../Entity/GamePlayer.h"
#include "FactoryService.h"
#include "../Defines.h"


InputService::InputService(AGameMap* gm) 
{
    lastPlayer = gm->Player2;
    gameMap = gm;
    actionService = new ActionService();
    timerService = gm->GetWorld()->SpawnActor<ATimerService>(ATimerService::StaticClass());
    timerService->SetGameMapInstance(gm);
    factoryService = new FactoryService();
}

InputService* InputService::getInstance(AGameMap* gm)
{
    if (instance == nullptr) {
        instance = new InputService(gm);
    }
    return instance;
}

void InputService::SendCommand(FString action, AGamePlayer *source)
{
    if(lastPlayer == source)
        return;
    if (gameMap->getNumOfTurns() < 1) {
        startQueue(action, source);
        return;
    }
    if(!timerService->bIsFinished)
        return;
    timerService->StartTimer(TIME_TIL_NEXT_TURN);
    
    lastPlayer = source;
    if (factoryService->InputAction(action, source))
    {
        actionService->ExecuteActions(factoryService->InputAction(action, source)->CreateActionCommand(action, source), source);
    }
    if (source == gameMap->Player2)
    {
        gameMap->NextTurn();
    }
}

void InputService::startQueue(FString action, AGamePlayer* source) {
    source->Name = action;
    lastPlayer = source;
    if (lastPlayer == gameMap->Player2)
        gameMap->NextTurn();
}

InputService* InputService::instance = 0;
