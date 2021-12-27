// Fill out your copyright notice in the Description page of Project Settings.


#include "BuyingCommandFactory.h"

BuyingCommandFactory::BuyingCommandFactory()
{
}

BuyingCommandFactory::~BuyingCommandFactory()
{
}

TArray<ActionCommand> BuyingCommandFactory::CreateActionCommand(FString action, AGamePlayer* player)
{
	TArray<ActionCommand> commands;
	if (IsValidCommand(action)) {
		vector<string> inputs = getParsedData(action);
		vector<string>::iterator it = inputs.begin();
		++it;
		while (it != inputs.end()) {
			int cardID;
			string input = *it;
			cardID = stoi(string(1, input[1]));
		/*	switch(input[1]) {
			case '0':
				card = AWater;
				break;
			case '1':
				card = AMole;
				break;
			case '2':
				card = AFertilizer;
				break;
			case '3':
				card = APlant("palnt 1");
				break;
			case '4':
				card = APlant("palnt 2");
				break;
			case '5':
				card = APlant("palnt 3");
				break;
			case '6':
				card = APlant("palnt 4");
				break;
			default:
				// code block
			}*/
			int amount = stoi(input.substr(3, input.length()-1));
			BuyingActionCommand command(cardID, amount);
			commands.Add(command);
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
	for (int i = 1; i <= result.size(); i++) {
		string elem = result.at(i);
		if ((elem[0] != '[') || (elem[2] != ',') || (elem.back() != ']')) {
			return false;
		}
		if (!isalpha(elem[1]) || elem[1] >= 7 || is_number(elem.substr(3, elem.length()-1)) || elem[3] < 1) {		// check if first param is in range 0-6 and second is number
			return false;
		}
	}
	return true;
}
