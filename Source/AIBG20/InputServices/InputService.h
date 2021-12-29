#pragma once

#include "CoreMinimal.h"

class AGameMap;
class AGamePlayer;
class InputService;
class ActionService;
class ATimerService;
class FactoryService;


#define WAIT_TIME 0.5

class AIBG20_API InputService
{
public:
    static InputService* getInstance(AGameMap* gm);
    void SendCommand(FString action, AGamePlayer *source);
private:
    AGameMap* gameMap;
    AGamePlayer* lastPlayer;
    static InputService* instance;
    ActionService* actionService;
    FactoryService* factoryService;  
    ATimerService* timerService;
    InputService(AGameMap* gm);
    void startQueue(FString action, AGamePlayer* source);

};