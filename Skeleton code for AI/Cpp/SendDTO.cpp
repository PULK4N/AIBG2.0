#include <string>
#include <list>
#include "ReceiveDTO.cpp"
using namespace std;

class Action {
public:
	int x;
	int y;
	int cardId;
	int amount;
	Action(int x = 0, int y = 0, int cardId = 0, int amount = 0) {
		this->x = x;
		this->y = y;
		this->cardId = cardId;
		this->amount = amount;
	}
};

class InputAction {
public:
	string actionType;
	list<Action> properties;
	InputAction(string actionType, list<Action> properties) {
		this->actionType = actionType;
		this->properties = properties;
	}

	/*string toString() {}*/
};


