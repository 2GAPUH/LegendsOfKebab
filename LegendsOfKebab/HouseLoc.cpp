#include "Source.h"

//---entity count--
#define NPC_HL 0 //HL - house location
#define ENEMY_HL 0
//-----------------



void House(hero Laplas) {
	char locations[5][20] = { "maps/map.txt","maps/house.txt", "maps/cave.txt", "maps/shop.txt", "maps/kebab_room.txt" };
	int startLocation = HOUSE;
	int currentLocation = HOUSE;
	PlaySound(L"main_full.wav", NULL, SND_LOOP | SND_ASYNC);
	AnLocCord LocAnCor[1] = { { 59, 20, 12 , 13, FIRST_LOCATION}};
	char map[WINDOW_HEIGHT][WINDOW_WIDTH];

	GetMapFromFile(locations[currentLocation], map);
	Hero hero = { 59 , 17 };
	PrintMap(hero, map, NULL, NULL);
	while (true)
	{
		//GetMapFromFile(locations[currentLocation], map);
		PrintMap(hero, map, NULL, NULL);
		heroMovement(&hero, map, Laplas);
		heroColision(hero, NULL, NULL, LocAnCor, currentLocation, Laplas, map);
		goNextLocation(startLocation, currentLocation, 12, 13, Laplas);
	}
}