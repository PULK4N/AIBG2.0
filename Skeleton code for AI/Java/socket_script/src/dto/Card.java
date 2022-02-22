package dto;

public class Card {
    private int Id;
    private boolean owned;

    public Card(int id, boolean owned) {
        this.Id = id;
        this.owned = owned;
    }

    public Card() {
    }

    public int getId() {
        return Id;
    }

    public void setId(int Id) {
        this.Id = Id;
    }

    public boolean isOwned() {
        return owned;
    }

    public void setOwned(boolean owned) {
        this.owned = owned;
    }

    public String getNameById(int id) {
        if(id == 0)
            return "WATER_CARD";
        else if(id == 1)
            return "MOLE_CARD";
        else if(id == 2)
            return "FERTILIZER_CARD";
        else if(id == 3)
            return "ANEMONE_FLOWER_CARD";
        else if(id == 4)
            return "BLUE_JAZZ_CARD";
        else if(id == 5)
            return "CROCUS_FLOWER_CARD";
        else if(id == 6)
            return "TULIP_CARD";
        return "";
    }

    @Override
    public String toString() {
        return
                "Owned = " + owned +
                ", name = " + getNameById(this.Id) + "\n";
    }
}
