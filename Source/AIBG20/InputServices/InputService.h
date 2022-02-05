#pragma once

#include "CoreMinimal.h"

class AGameMap;
class AGamePlayer;
class InputService;
class ActionService;
class ATimerService;
class FactoryService;
class AOutputService;

#define WAIT_TIME 0.5

class AIBG20_API InputService
{
public:
    static InputService* getInstance(AGameMap* gm);
    void SendCommand(FString action, AGamePlayer *source);
    ~InputService();
    void ClearTimers();
private:
    AGameMap* gameMap;
    static InputService* instance;
    ActionService* actionService;
    FactoryService* factoryService;  
    ATimerService* timerService;
    AOutputService* outputService;
    InputService(AGameMap* gm);
    void startQueue(FString action, AGamePlayer* source);
};