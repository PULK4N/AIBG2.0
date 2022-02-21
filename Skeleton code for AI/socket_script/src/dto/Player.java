package dto;

import java.util.List;

public class Player {
    private int points;
    private int gold;
    private boolean fertilizerActive;
    private List<Tile> tiles;
    private List<Card> cards;

    public Player(int points, int gold, boolean fertilizerActive, List<Tile> tiles, List<Card> cards) {
        this.points = points;
        this.gold = gold;
        this.fertilizerActive = fertilizerActive;
        this.tiles = tiles;
        this.cards = cards;
    }

    public Player() {
    }

    public int getPoints() {
        return points;
    }

    public void setPoints(int points) {
        this.points = points;
    }

    public int getGold() {
        return gold;
    }

    public void setGold(int gold) {
        this.gold = gold;
    }

    public boolean isFertilizerActive() {
        return fertilizerActive;
    }

    public void setFertilizerActive(boolean fertilizerActive) {
        this.fertilizerActive = fertilizerActive;
    }

    public List<Tile> getTiles() {
        return tiles;
    }

    public void setTiles(List<Tile> tiles) {
        this.tiles = tiles;
    }

    public List<Card> getCards() {
        return cards;
    }

    public void setCards(List<Card> cards) {
        this.cards = cards;
    }

    @Override
    public String toString() {
        StringBuilder tilesString = new StringBuilder();
        for (Tile tile : tiles) {
            tilesString.append(tile.toString());
        }
        StringBuilder cardsString = new StringBuilder();
        for (Card card : cards) {
            cardsString.append(card.toString());
        }
        return "Points = " + points +
                ", Gold = " + gold +
                ", Fertilizer active for " + fertilizerActive +
                " turns " + tilesString + " " + cardsString + "\n";
    }
}
