package action;

import com.fasterxml.jackson.annotation.JsonAutoDetect;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.IOException;

@JsonAutoDetect
public class Action {
    private int x;
    private int y;
    private int cardId;
    private int amount;

    public Action(int x, int y, int cardId, int amount) {
        this.x = x;
        this.y = y;
        this.cardId = cardId;
        this.amount = amount;
    }

    public Action() {
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getCardId() {
        return cardId;
    }

    public void setCardId(int cardId) {
        this.cardId = cardId;
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }
}
