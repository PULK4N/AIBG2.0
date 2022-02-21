package action;

import com.fasterxml.jackson.annotation.JsonAutoDetect;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.IOException;
import java.util.List;

@JsonAutoDetect
public class InputAction {
    private char actionType;
    private List<Action> properties;

    public InputAction(char actionType, List<Action> properties) {
        this.actionType = actionType;
        this.properties = properties;
    }

    public InputAction() {
    }

    public char getActionType() {
        return actionType;
    }

    public void setActionType(char actionType) {
        this.actionType = actionType;
    }

    public List<Action> getProperties() {
        return properties;
    }

    public void setProperties(List<Action> properties) {
        this.properties = properties;
    }

    public String toJSON() {
        ObjectMapper mapper = new ObjectMapper();
        String json = null;
        try {
            json = mapper.writeValueAsString(this);
            System.out.println(json);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return json;
    }
}
