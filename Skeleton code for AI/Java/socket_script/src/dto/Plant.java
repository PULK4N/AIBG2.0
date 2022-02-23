package dto;

import com.fasterxml.jackson.annotation.JsonAutoDetect;

@JsonAutoDetect
public class Plant {
    private int plantId;
    private int goldWorth;
    private int waterNeeded;
    private int daysToRot;

    public Plant(int plantId, int goldWorth, int waterNeeded, int daysToRot) {
        this.plantId = plantId;
        this.goldWorth = goldWorth;
        this.waterNeeded = waterNeeded;
        this.daysToRot = daysToRot;
    }

    public Plant() {
    }

    public int getPlantId() {
        return plantId;
    }

    public void setPlantId(int plantId) {
        this.plantId = plantId;
    }

    public int getGoldWorth() {
        return goldWorth;
    }

    public void setGoldWorth(int goldWorth) {
        this.goldWorth = goldWorth;
    }

    public int getWaterNeeded() {
        return waterNeeded;
    }

    public void setWaterNeeded(int waterNeeded) {
        this.waterNeeded = waterNeeded;
    }

    public int getDaysToRot() {
        return daysToRot;
    }

    public void setDaysToRot(int daysToRot) {
        this.daysToRot = daysToRot;
    }

    public String getNameById(int id) {
        if(id == 3)
            return "ANEMONE_FLOWER";
        else if (id == 4)
            return "BLUE_JAZZ";
        else if(id == 5)
            return "CROCUS_FLOWER";
        else if(id == 6)
            return "TULIP";
        return "None";
    }

    @Override
    public String toString() {
        return getNameById(this.plantId) +
                ", Gold worth = " + goldWorth +
                ", Water needed = " + waterNeeded + "\n";

    }
}
