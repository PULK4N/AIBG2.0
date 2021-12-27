// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCommandFactory.h"
#include "../Command/ActionCommand.h"



TArray<ActionCommand> ActionCommandFactory::CreateActionCommand(FString action, AGamePlayer *player) {
	TArray<ActionCommand> t;
	return t;
}

bool ActionCommandFactory::IsValidCommand(FString action) {
	return true;
}

vector<string> ActionCommandFactory::getParsedData(FString action)
{
	string s = TCHAR_TO_UTF8(*action);
	vector<string> result;
	stringstream s_stream(s);
	while (s_stream.good()) {
		string substr;
		getline(s_stream, substr, ';'); //get first string delimited by semicolon
		result.push_back(substr);
	}
	return result;
}