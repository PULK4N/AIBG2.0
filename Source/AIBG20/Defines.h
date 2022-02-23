#pragma once
//----- CardID-s ------
#define TESTPLANT_CARD_ID -1
#define WATER_CARD_ID 0
#define MOLE_CARD_ID 1
#define FERTILIZER_CARD_ID 2
#define ANEMONE_FLOWER_CARD_ID 3
#define BLUE_JAZZ_CARD_ID 4
#define CROCUS_FLOWER_CARD_ID 5
#define TULIP_CARD_ID 6
	
//----- Prices ------
#define TILE_COST 5000
#define WATER_COST 200
#define MOLE_COST 10000
#define FERTILIZER_COST 3000
#define ANEMONE_FLOWER_COST 500
#define BLUE_JAZZ_COST 500
#define CROCUS_FLOWER_COST 1000
#define TULIP_COST 3600

//------ Water needed ------
#define ANEMONE_FLOWER_WATER_NEEDED 2
#define BLUE_JAZZ_WATER_NEEDED 2
#define CROCUS_FLOWER_WATER_NEEDED 5
#define TULIP_WATER_NEEDED 1

//------ Days to rot ------
#define ANEMONE_FLOWER_DAYS_TO_ROT 5
#define BLUE_JAZZ_DAYS_TO_ROT 4
#define CROCUS_FLOWER_DAYS_TO_ROT 4
#define TULIP_DAYS_TO_ROT 3

//------ Gold worth ------
#define ANEMONE_FLOWER_GOLD_WORTH 2000
#define BLUE_JAZZ_GOLD_WORTH 2500
#define CROCUS_FLOWER_GOLD_WORTH 5000
#define TULIP_GOLD_WORTH 8000

//-------   Timers  ------
#define TIME_TIL_NEXT_TURN 0.5f //0.5f
#define TIME_TIL_PLAYER_SWITCH 6.0f
#define TIME_TIL_SOCKET_RECIEVES_INPUT 0.3f
#define TIME_TIL_SOCKET_RECIEVES_CONNECTION 1.0f
//-------  Rain     ------
#define RAIN_DAY 10
#define RAIN_WATER_DROPS 2
//-------Animations ------
#define ANIMATION_IS_ON true
//-------  GameEnd  ------
#define GAME_END_TURN 100

//------- Others --------
#define MAX_AMOUNT_OF_CARDS_TO_BUY 100000
#define NOT_PLAYED_TURNS_DISQUALIFY 3