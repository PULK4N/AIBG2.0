import json
#### DTO Classes
class InputAction:
    def __init__(self, actionType, properties):
        self.ActionType = actionType
        self.Properties = properties
        
        
    def toJSON(self):
        return json.dumps(self, default=lambda obj: obj.__dict__)
class Action:
    def __init__(self, x = 0, y = 0, cardid = 0, amount = 0):
        self.X = x
        self.Y = y
        self.Cardid = cardid
        self.Amount = amount