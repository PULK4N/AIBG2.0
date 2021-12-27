#include "InputService.h"

void InputService::SendCommand(FString action, AGamePlayer *source)
{
    if(this.lastPlayer == source) 
        return;
    if(!this.timerService.TimerFinished())
        return;
    this.timerService.StartTimer(WAIT_TIME);
    this.lastPlayer = source;
    // update turns in GameMap
    this->factoryService = new FactoryService();
	this->factoryService.CreateActionCommand(action, source);
    this.actionService.ExecuteActions(actionCommands, source);
}
