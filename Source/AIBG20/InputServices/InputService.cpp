#include "InputService.h"
#include "../Entity/GameMap.h"


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
    if(this->lastPlayer == source)
        return;
    if(!this->timerService->TimerFinished())
        return;
    this->timerService->StartTimer(WAIT_TIME);
    this->lastPlayer = source;
    // change turns
    if (this->factoryService->InputAction(action, source))
    {
        this->actionService->ExecuteActions(this->factoryService->InputAction(action, source)->CreateActionCommand(action, source), source);
    }
}

InputService* InputService::instance = 0;
