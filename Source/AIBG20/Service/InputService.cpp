// Fill out your copyright notice in the Description page of Project Settings.


#include "InputService.h"
#include "../Entity/GamePlayer.h"

InputService::InputService()
{

}

InputService* InputService::getInstance()
{
	if (instance == nullptr) {
		instance = new InputService;
	}
	return instance;
}

InputService::~InputService()
{

}

void InputService::SendCommand(FString Command, AGamePlayer* source) {
	if (source == this->lastPlayer) {
		return;
	}

	//if (TimerNotFinished()) {
	//	return;
	//}
	//startTimer();

	lastPlayer = source;
}

InputService* InputService::instance = 0;
