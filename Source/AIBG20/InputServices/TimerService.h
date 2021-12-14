#include "ActionService.h"
#include "FactoryService.h"

class AIBG20_API TimerService
{
public:
    bool timing;
    void StartTimer(float sec);
    bool TimerFinished();
};