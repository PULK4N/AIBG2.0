using System.Collections.Generic;
using System.Text.Json;

namespace AIBG
{
    public class InputAction
    {
        public string ActionType { get; set; }
        public List<Action> Properties { get; set; }

        public InputAction(string type, List<Action> props)
        {
            ActionType = type;
            Properties = props;
        }

        public string ToJSON()
        {
            return JsonSerializer.Serialize(this);
        }
    }

    public class Action
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int CardId { get; set; }
        public int Amount { get; set; }

        public Action(int x, int y, int id, int amount)
        {
            X = x;
            Y = y;
            CardId = id;
            Amount = amount;
        }
     }
}
