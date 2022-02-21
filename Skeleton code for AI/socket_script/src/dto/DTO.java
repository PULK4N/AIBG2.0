package dto;

import com.fasterxml.jackson.annotation.JsonAutoDetect;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.IOException;
import java.util.List;

@JsonAutoDetect
public class DTO {
    private List<Tile> tiles;
    private Player source;
    private Player enemy;
    private int daysTillRain;

    public DTO() {
    }

    public DTO(List<Tile> tiles, Player source, Player enemy, int daysTillRain) {
        this.tiles = tiles;
        this.source = source;
        this.enemy = enemy;
        this.daysTillRain = daysTillRain;
    }

    public List<Tile> getTiles() {
        return tiles;
    }

    public void setTiles(List<Tile> tiles) {
        this.tiles = tiles;
    }

    public Player getSource() {
        return source;
    }

    public void setSource(Player source) {
        this.source = source;
    }

    public Player getEnemy() {
        return enemy;
    }

    public void setEnemy(Player enemy) {
        this.enemy = enemy;
    }

    public int getDaysTillRain() {
        return daysTillRain;
    }

    public void setDaysTillRain(int daysTillRain) {
        this.daysTillRain = daysTillRain;
    }

    @Override
    public String toString() {
        return "DTO{" +
                "tiles=" + tiles +
                ", source=" + source +
                ", enemy=" + enemy +
                ", daysTillRain=" + daysTillRain +
                '}';
    }

    public static DTO from_json(String json_string) {
        DTO dto = null;
        try {
            ObjectMapper objectMapper = new ObjectMapper();
            dto = objectMapper.readValue(json_string, DTO.class);
            System.out.println(dto);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return dto;
    }
}
