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
    factoryService = new FactoryService();
}

InputService::~InputService(){
    delete factoryService;
    delete actionService;
    instance = nullptr;
    UE_LOG(LogTemp, Warning, TEXT("InputService deleted"));
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
    {//maybe add mutex - FScopeLock
        if (gameMap->OnTheMovePlayer != source) {
            source->SendOutput("It's not your turn yet");
            return;
        }
        //if first turn, wait for both players to input a name
        if (gameMap->getNumOfTurns() < 1) {
            startQueue(action, source);
            return;
        }
        //if timer has not finished return
        if(!timerService->bIsFinished)
            return;
        //all went okay, clear rest of the timerers
        //timerService->GetWorldTimerManager().ClearAllTimersForObject(timerService);
        ////wait 'TIME_TIL_NEXT_TURN' - time for animation to finish and then allow next player to input something
        //timerService->StartTimer(TIME_TIL_NEXT_TURN);
        //
        if (factoryService->InputAction(action, source))
        {
            actionService->ExecuteActions(factoryService->InputAction(action, source)->CreateActionCommand(action, source), source);
        }
    }
    //gameMap->SwitchPlayers(); //if timers are commented, add this
}

void InputService::startQueue(FString action, AGamePlayer* source) {
    source->Name = action;
    gameMap->SwitchPlayers();
}

void InputService::ClearTimers() {
    timerService->ClearTimers();
}

InputService* InputService::instance = 0;
