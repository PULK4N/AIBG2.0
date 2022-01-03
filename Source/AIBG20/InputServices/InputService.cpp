#include "InputService.h"
#include "../Entity/GameMap.h"
#include "ActionService.h"
#include "FactoryService.h"
#include "TimerService.h"
#include "../Entity/GamePlayer.h"
#include "../Service/OutputService.h"
#include "FactoryService.h"
#include "../Defines.h"


InputService::InputService(AGameMap* gm) 
{
    gameMap = gm;
    gameMap->OnTheMovePlayer = gm->Player1;
    actionService = new ActionService();
    timerService = gm->GetWorld()->SpawnActor<ATimerService>(ATimerService::StaticClass());
    timerService->SetGameMapInstance(gm);
    outputService = gm->GetWorld()->SpawnActor<AOutputService>(AOutputService::StaticClass());
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
    if(gameMap->OnTheMovePlayer != source)
        return;
    //if first turn, wait for both players to input a name
    if (gameMap->getNumOfTurns() < 1) {
        startQueue(action, source);
        return;
    }
    //if timer has not finished return
    //if(!timerService->bIsFinished)
    //    return;
    ////all went okay, clear rest of the timerers
    //timerService->GetWorldTimerManager().ClearAllTimersForObject(timerService);
    ////wait 'TIME_TIL_NEXT_TURN' - time for animation to finish and then allow next player to input something
    //timerService->StartTimer(TIME_TIL_NEXT_TURN);
    //
    gameMap->SwitchPlayers();
    if (factoryService->InputAction(action, source))
    {
        actionService->ExecuteActions(factoryService->InputAction(action, source)->CreateActionCommand(action, source), source);
    }
    if (source == gameMap->Player2)
    {
        gameMap->NextTurn();
    }
    outputService->SendOutput(gameMap,gameMap->OnTheMovePlayer);
}

void InputService::startQueue(FString action, AGamePlayer* source) {
    source->Name = action;
    gameMap->SwitchPlayers();
}

InputService* InputService::instance = 0;
