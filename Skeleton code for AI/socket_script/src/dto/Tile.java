package dto;

import com.fasterxml.jackson.annotation.JsonAutoDetect;

@JsonAutoDetect
public class Tile {
    private int x;
    private int y;
    private boolean bIsPlanted;
    private boolean bIsSpecial;
    private Plant plantDTO;

    public Tile(int x, int y, boolean bIsPlanted, boolean bIsSpecial, Plant plantDTO) {
        this.x = x;
        this.y = y;
        this.bIsPlanted = bIsPlanted;
        this.bIsSpecial = bIsSpecial;
        this.plantDTO = plantDTO;
    }

    public Tile() {
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

    public boolean isbIsPlanted() {
        return bIsPlanted;
    }

    public void setbIsPlanted(boolean bIsPlanted) {
        this.bIsPlanted = bIsPlanted;
    }

    public boolean isbIsSpecial() {
        return bIsSpecial;
    }

    public void setbIsSpecial(boolean bIsSpecial) {
        this.bIsSpecial = bIsSpecial;
    }

    public Plant getPlantDTO() {
        return plantDTO;
    }

    public void setPlantDTO(Plant plantDTO) {
        this.plantDTO = plantDTO;
    }

    @Override
    public String toString() {
        return "Coordination = [" + x + "," + y + "]" +
                ", planted = " + bIsPlanted +
                ", special = " + bIsSpecial +
                ", plant = " + plantDTO + "\n";
    }
}
