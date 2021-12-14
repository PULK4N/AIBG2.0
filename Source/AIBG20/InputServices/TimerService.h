#include "ActionService.h"
#include "FactoryService.h"
#include "TimerService.h"

class AIBG20_API TimerService
{
public:
    bool timing;
    void StartTimer(float sec);
    bool TimerFinished();
};