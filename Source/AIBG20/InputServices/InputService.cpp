#include "InputService.h"
#include "../Entity/GameMap.h"
#include "ActionService.h"
#include "FactoryService.h"
#include "TimerService.h"
#include "../Entity/GamePlayer.h"
#include "FactoryService.h"


InputService::InputService(AGameMap* gm) 
{
    gameMap = gm;
    actionService = new ActionService();
    timerService = new TimerService();
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
    if(!timerService->TimerFinished())
        return;
    timerService->StartTimer(WAIT_TIME);
    lastPlayer = source;
    // change turns
    if (factoryService->InputAction(action, source))
    {
        actionService->ExecuteActions(factoryService->InputAction(action, source)->CreateActionCommand(action, source), source);
    }
}

InputService* InputService::instance = 0;
