#include "ActionCommandFactory.h"

#DEFINE WAIT_TIME 0.5

class AIBG20_API FactoryService
{
public:
    ActionCommandFactory* InputAction(FString action, AGamePlayer *player);
    ActionCommandFactory actionCommandFactory;
};