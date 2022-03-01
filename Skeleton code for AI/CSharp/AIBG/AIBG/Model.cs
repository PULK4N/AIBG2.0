using System.Collections.Generic;
using System.Text.Json.Serialization;

namespace AIBG
{
    public class Plant
    {
        [JsonInclude]
        public int PlantId { get; set; }
        [JsonInclude]
        public int GoldWorth { get; set; }
        [JsonInclude]
        public int WaterNeeded { get; set; }

        public Plant(int id, int goldWorth, int waterNeeded)
        {
            PlantId = id;
            GoldWorth = goldWorth;
            WaterNeeded = waterNeeded;
        }

        public static Plant GetPlantFromJSON(string json)
        {
            return Newtonsoft.Json.JsonConvert.DeserializeObject<Plant>(json);
        }

        public string GetNameFromId()
        {
            return PlantId switch
            {
                3 => "ANEMONE_FLOWER",
                4 => "BLUE_JAZZ",
                5 => "CROCUS_FLOWER",
                6 => "TULIP",
                _ => "None",
            };
        }

        public override string ToString()
        {
            return $"\n\t\t{GetNameFromId()}, GoldWorth = {GoldWorth}, Water needed = {WaterNeeded}\n";
        }
    }

    public class Tile
    {
        public int X { get; set; }
        public int Y { get; set; }
        public bool BIsPlanted { get; set; }
        public bool BIsSpecial { get; set; }
        public Plant PlantDTO { get; set; }

        public Tile(int x, int y, bool bIsPlanted, bool bIsSpecial, Plant plantDTO)
        {
            X = x;
            Y = y;
            BIsPlanted = bIsPlanted;
            BIsSpecial = bIsSpecial;
            PlantDTO = plantDTO;
        }

        public Tile GetTileFromJSON(string json)
        {
            return Newtonsoft.Json.JsonConvert.DeserializeObject<Tile>(json);
        }

        public override string ToString()
        {
            return $"\n\tCoordinations = [{X},{Y}], planted = {BIsPlanted}, Special tile = {BIsSpecial} {PlantDTO}\n";
        }
    }

    public class Card
    {
        public int CardId { get; set; }
        public int Owned { get; set; }

        public Card(int id, int owned)
        {
            CardId = id;
            Owned = owned;
        }

        public Card GetCardFromJSON(string json)
        {
            return Newtonsoft.Json.JsonConvert.DeserializeObject<Card>(json);
        }

        public string GetNameFromId()
        {
            return CardId switch
            {
                0 => "WATER_CARD",
                1 => "MOLE_CARD",
                2 => "FERTILIZER_CARD",
                3 => "ANEMONE_FLOWERR_CARD",
                4 => "BLUE_JAZZR_CARD",
                5 => "CROCUS_FLOWERR_CARD",
                6 => "TULIPR_CARD",
                _ => "",
            };
        }

        public override string ToString()
        {
            return $"\n\tOwned {Owned} {GetNameFromId()}";
        }
    }

    public class Player
    {
        public int Points { get; set; }
        public int Gold { get; set; }
        public bool FertilizerActive { get; set; }
        public List<Tile> Tiles { get; set; }
        public List<Card> Cards { get; set; }

        public Player(int points, int gold, bool fertilizerActive, List<Tile> tiles, List<Card> cards)
        {
            Points = points;
            Gold = gold;
            FertilizerActive = fertilizerActive;
            Tiles = tiles;
            Cards = cards;
        }

        public Player GetPlayerFromJSON(string json)
        {
            return Newtonsoft.Json.JsonConvert.DeserializeObject<Player>(json);
        }

        public override string ToString()
        {
            string tiles = "";
            foreach (Tile t in Tiles)
                tiles += t;
            string cards = "";
            foreach (Card c in Cards)
                cards += c;
            return $"\nGold = {Gold}, Points = {Points} Fertilizer active for {FertilizerActive} turns {tiles} {cards}\n";
        }
    }

    public class DTO
    {
        public List<Tile> Tiles { get; set; }
        public Player Source { get; set; }
        public Player Enemy { get; set; }
        public int DaysTillRain { get; set; }

        public DTO(List<Tile> tiles, Player source, Player enemy, int daysTillRain)
        {
            Tiles = tiles;
            Source = source;
            Enemy = enemy;
            DaysTillRain = daysTillRain;
        }

        public static DTO GetDTOFromJSON(string json)
        {
            try
            {
                return Newtonsoft.Json.JsonConvert.DeserializeObject<DTO>(json);
            }
            catch
            {
                return null;
            }
        }

        public override string ToString()
        {
            string tiles = "";
            foreach (Tile t in Tiles)
                tiles += t;
            return $"Tiles = {tiles} \nMy info = \n {Source} \nEnemy info = \n {Enemy} \nDays till rain = {DaysTillRain}";
        }
    }
}
