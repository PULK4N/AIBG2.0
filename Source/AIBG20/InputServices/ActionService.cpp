#include "ActionService.h"

void ActionService::ExecuteActions(TArray<ActionCommand> actionCommands, AGamePlayer* player) {
    for (ActionCommand ac:actionCommands)
        ac.Execute();
}
