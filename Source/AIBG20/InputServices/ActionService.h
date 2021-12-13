#include "ActionCommandFactory.h"

class AIBG20_API ActionService
{
public:
    bool ExecuteActions(TArray<ActionCommand> actionCommands, AGamePlayer*player);

};