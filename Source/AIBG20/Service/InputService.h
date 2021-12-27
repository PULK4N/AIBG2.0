// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AGamePlayer;

/**
 * 
 */
class AIBG20_API InputService
{
public:
    static InputService* getInstance();
    void SendCommand(FString Command, AGamePlayer* source);
    ~InputService();
private:
    InputService();
    AGamePlayer* lastPlayer;
    static InputService* instance;
};
