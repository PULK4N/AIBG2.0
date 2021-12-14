#inclue "TimerService.h"
#include<windows.h>

void TimerService::StartTimer(float sec)
{
    // postavi da se meri vreme i kada prodje sec sekundi postavi da se ne meri vise
    this.timing = true;
    Sleep(sec*1000);
    this.timing = false;
}

bool TimerService::TimerFinished()
{
    return this.timing == false;
}