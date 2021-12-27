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
    void SendCommand(FString action, AGamePlayer *source);
private:
    AGameMap* gameMap;
    AGamePlayer* lastPlayer;
    static InputService* instance;
    ActionService* actionService;
    FactoryService* factoryService;  
    TimerService* timerService;
    InputService(AGameMap* gm);

};