# AI gardening war - Game developed for Artificial Intelligence BattleGround v2.0

### Team members 👯
#### Developers:
- [Anđela Mišković](https://github.com/andjmiskovic)
- [Dejan Tosenberger](https://github.com/DejanT98)
- [Igor Jakovljević](https://github.com/igorjakovljevic-ftn)
- [Milan Ajder](https://github.com/mmmajder)
- [Mihajlo Živković](https://github.com/mehighlovv)
#### Designers:
- [Strahinja Bogunović](https://github.com/strahinjabogunovic)
- [Miloš Nestorović](https://github.com/strahinjabogunovic)

#### Team lead
- Nikola Pupovac

---
## Project Setup guide
### Unreal engine version 4.27
- After downloading everything from git it's necessary to download files from [drive](https://drive.google.com/file/d/16YsebQ0FomVdrHPifpeEpNk8SmCfC74e/view?usp=sharing)
- After downloading the files from drive, copy them to \Content\

---


## Game specification

The game is played on a board measuring 8x8, where each field represents a piece of land on which something can be planted. There is a store where players buy certain resources that they need. They will need plant seeds, water, as well as various special cards with which they will help the growth of their seedlings, increase their earnings or sabotage another player.
The goal of the game is to collect as many points as possible, and the only way to collect points is to pick mature plants. By picking plants, you get a certain amount of money and points. You spend money on in-store purchases, while points are used to record your success.
The game is played alternately, one player after another. The board will be symmetrical so that both players have the same chance of winning. The winner is the one who has more points at the end of the game. The game lasts 100 moves.
#### Board
As previously mentioned, the board looks like an 8x8 matrix (see picture below). Each field represents an arable area. Players start from opposite corners of the board (one from the bottom left and the other from the top right). Players can only plant something on their territory. At the beginning of the game, they have 1 field, and during the game, they can buy land, but only if the field they want to buy borders on their property at the time of purchase. When players send requests to the server, they will use field coordinate tags. Marks in the form (x, y) indicate the coordinates on the map observed in relation to the coordinate system so that (0, 0) the field is below left (blue field), and (7, 7) above right (red field).
Fields with a yellow border represent special fields. By planting plants in special fields, the player gets twice as much money and points. For example, if a plant yields money worth 1000, the player will receive 2000 when he picks up fruits that have grown in a special field.
![alt text](https://github.com/PULK4N/AIBG2.0/blob/master/tiles.jpg?raw=true)

#### Shop
Players have 5,000 coins at the beginning of the game. They can buy as many things as they want in one go, of course, if they have enough money at the moment. Any request they send for a purchase will be rejected if the account exceeds their current capabilities.
Available products in the store are:
- Flowers (plants)
  - Players will be able to choose between 4 types of plants to plant. Each plant will have a different price, as well as the amount of money and points that will bear fruit.
  - Each flower (plant) needs to be watered a certain number of times, so that it blooms and can be turned over. Information on prices and the number of waterings required can be found in the Specification Details section.
  - If the plant is watered with more drops than it needs, the plant dies. Weeds remain in that field, which must be uprooted in order to be replanted in that field.
  - The more expensive the plant, the more money and points the fruit will bring to the player.
  - The purchase of seeds takes place by the player forwarding the purchase request where he will state which seeds he wants and in what quantity he needs them.
  - The plant has its own lifespan, which lasts a few strokes. If the plant is not harvested by then, it decays and its value becomes 0. The failed plant must be turned over so that a new plant can be planted in that field.
 - Water
   - Drop = a measure for an amount of water necessary to water one field.
 - Tile
   - Based on the land purchase rules listed in the Table section, players can expand their territory by purchasing adjacent fields on the table if they are free (not owned by another player).
   - It is possible to buy several fields at once in a move.
   - It is stated above that only adjacent fields can be purchased, so it is necessary to pay attention to the order of the fields that are purchased. If, for example, a player owns a field (0,0) and passes the command to buy a field (1,1), (2,1), (3,1), the player will buy those 3 fields (assuming he has enough money). However, if he bought the fields in order (3,1), (1,1), (2,1), the player would only buy the fields (1,1) and (2,1).
 - Special cards
   - 2 types
     - Fertilizer
       - Activating this card allows the player to double the yield from harvesting plants. If a player has activated fertilizer and has planted a plant in a special field, he will get 4 times higher yield when he harvests that plant!
       - Fertilizer lasts 2 next moves. This means that if you have activated the fertilizer in the current move, the next 2 moves you can get twice the yield due to the fertilizer.
       - It is possible to have the duration of the fertilizer more moves, by activating it several moves in a row (eg in move 1 you activate the fertilizer, and it applies to moves 2 and 3, then in move 2 you activate the fertilizer and it applies to moves 3,4, 5.6).
     - Mole
       - Activating this card allows the player to take one field from the opponent. If a plant is currently planted in that field, the plant disappears.
       - For example, it may happen that a player is captured by an opponent and is unable to expand his territory further; in that case, activating this card can help him free himself by selecting the opponent's field he wants to take.
#### Possible moves
Since the players play alternately, everyone has the right to choose one of the possible actions in their move:
 - Buying a field
   - A player can buy any field adjacent to the field he owns.
   - A player can buy more fields in the same move.
   - If a player buys a field, he can buy adjecent fields, e.g. if a player owns a field (0.0), he can buy (1.1), (2.2), (3.3) in one move.
 - Shopping
   - A player can buy anything in any quantity in one move (if he has enough money).
 - Planting
   - The player can plant any type of plant (for which he has enough seeds) in any of his fields.
   - For example, a player's request would read: "in this move I want to plant a tulip in the fields (1, 4), (1, 5) and (1, 6), and an anemone flower in the fields (2) , 3) and (2, 4). ” If the specified fields are not in the player's possession, the move is considered invalid and will not be considered. If the player does not have enough seeds (in this case it would be 3 rose seeds and 2 strawberry seeds, but there are only 3 roses, for example), the player will plant a tulip in the above 3 fields, while the anemone flower will not be planted.
 - Watering
   - Similar to planting, the player will specify the coordinates of the field he wants to water. If there are not enough drops of water, the move will be considered invalid. Each plant will receive as many drops as the player wrote. If a mature plant is watered, it perishes.
 - Harvesting
   - By choosing this action, all mature and failed plants in the possession of the player will be harvested. After picking, the player gets money and points, and the field becomes ready for the next planting. The plant has a certain lifespan, if we do not water the plant to mature and harvest it by the end of its lifespan, it will perish. By picking the failed plants, the player does not get any yield.
 - Activating special cards
   - It is possible to activate 1 special card per move. (mole or fertilizer)

#### Specifications
- Values for plants

|              | Anemone flower | BlueJazz | Crocus flower | Tulip        |
| ------------ | -------------- | -------- | ------------- | ------------ |
| Water needed | 2              | 2        | 5             | 1            |
| Life cycle   | 5 moves        | 4 moves  | 4 moves       | 3 moves      |
| Gold gained  | 2000           | 2500     | 5000          | 8000         |

- prices

| Product name   | Price  |
| -------------- | ------ |
| Tile           | 5000   |
| Fertilizer     | 3000   |
| Water (1 drop) | 200    |
| Mole           | 10 000 |
| Anemone flower | 500    |
| BlueJazz       | 500    |
| Crocus flower  | 1000   |
| Tulip          | 3600   |

#### Other
 - It will rain every tenth move. Rain floods every field on the board with 2 drops. This helps players who have trained their robots well to plant plants before the rain. If they do not plan their moves well and it rains on the ripe fruits, the plants will rot.
 - For bot-bot and bot-against-game modes, bots must move within 6 seconds, otherwise the opponent changes. If the bot does not play a move 3 times, his points become 0 and he automatically loses.
 - If there is a draw, the game is played again. If there is a draw several times in a row, it is possible to increase the number of moves. If there is still a draw, the winner will be determined based on the value he has.
 - To play with the mouse against the bot, select the “Player vs Game” button.

#### Game ending
- After 100 moves, the game is over. The winner is the player who collected more points.

[Download Game](https://drive.google.com/file/d/1h9-ADe6mn8g_vf_DTjoE0ya4z7MTYUGW/view?usp=sharing)
---
### AI training
- Depending on your implementation language, competition contestants could use skeleton codes provided in /Skeleton code for AI/
- They could change options, depending on which player they desired, by editing settings, and could focus on impelmenting their bot in the function bot_input
