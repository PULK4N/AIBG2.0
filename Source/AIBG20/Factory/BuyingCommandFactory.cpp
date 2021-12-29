// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingCommandFactory.h"

BuyingCommandFactory::BuyingCommandFactory()
{
}

BuyingCommandFactory::~BuyingCommandFactory()
{
}

TArray<ActionCommand*> BuyingCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
	TArray<ActionCommand*> commands;
	if (IsValidCommand(action)) {
		vector<string> inputs = getParsedData(action);
		vector<string>::iterator it = inputs.begin();
		++it;
		while (it != inputs.end()) {
			int cardID;
			string input = *it;
			cardID = stoi(string(1, input[1]));
			int amount = stoi(input.substr(3, input.length()-1));
			commands.Add(new BuyingActionCommand(cardID, amount, player));
			++it;
		}
		return commands;
	}
	else {
		throw "Input is not valid";
	}
}

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

bool BuyingCommandFactory::IsValidCommand(FString action) 
{
    vector<string> result = getParsedData(action);

	if (result.at(0) != "C") {
		return false;
	}
	for (int i = 1; i < result.size(); i++) {
		string elem = result.at(i);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("elem[0]=%c elem[2]")));
		if ((elem[0] != '[') || (elem[2] != ',') || (elem.back() != ']')) {
			return false;
		}
		if (!isdigit(elem[1]) || (elem[1] - '0') >= 7 || is_number(elem.substr(3, elem.length()-1))) {		// check if first param is in range 0-6 and second is number
			return false;
		}
	}
	return true;
}
