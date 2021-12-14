#include "ActionService.h"
#include "FactoryService.h"
#include "TimerService.h"
#include "../Entity/GamePlayer.h"
#include "FactoryService.h"

#define WAIT_TIME 0.5

class AIBG20_API InputService
{
public:
    static InputService& getInstance()
    {
        static InputService instance;
        return instance;
    }
private:
    InputService() { }
    InputService(InputService const&);
    void operator = (InputService const&);
    
    AGamePlayer* lastPlayer;
    void SendCommand(FString action, AGamePlayer *source);
    ActionService actionService;
    FactoryService factoryService;  
    TimerService timerService;

};