#pragma once

#include "CoreMinimal.h"

class AIBG20_API TimerService
{
public:
    bool timing;
    void StartTimer(float sec);
    bool TimerFinished();
};