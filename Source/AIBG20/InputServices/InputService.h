#include "ActionService.h"
#include "FactoryService.h"
#include "TimerService.h"
#include "../Entity/GamePlayer.h"
#include "FactoryService.h"

class AGameMap;

#define WAIT_TIME 0.5

class AIBG20_API InputService
{
public:
    static InputService* getInstance(AGameMap* gm);
private:
    InputService(AGameMap gm);
    static InputService* instance;
    AGameMap* gameMap;
    AGamePlayer* lastPlayer;
    InputService(AGameMap* gm);
    void SendCommand(FString action, AGamePlayer *source);
    ActionService* actionService;
    FactoryService* factoryService;  
    TimerService* timerService;

};