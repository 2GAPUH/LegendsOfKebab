#include "Source.h"

//---entity count--
#define NPC_KL 0 //KL - kebab location
#define ENEMY_KL 0
//-----------------

void Kebab(hero Laplas) {
	system("chcp 1251");
	char locations[5][20] = { "maps/map.txt","maps/house.txt", "maps/cave.txt", "maps/kebab_room.txt", "maps/shop.txt" };
	int startLocation = KEBAB_ROOM;
	int currentLocation = KEBAB_ROOM;
	PlaySound(L"main_menu_full.wav", NULL, SND_LOOP | SND_ASYNC);
	AnLocCord locAnCor[1] = { { 0, 17, 117, 15, CAVE } };
	char map[WINDOW_HEIGHT][WINDOW_WIDTH];

	GetMapFromFile(locations[currentLocation], map); 
	Hero hero = { 2,17 };
	PrintMap(hero, map, NULL, NULL);
	while (true)
	{
		GetMapFromFile(locations[currentLocation], map);
		PrintMap(hero, map, NULL, NULL);
		heroMovement(&hero, map);
		heroColision(hero, NULL, NULL, locAnCor, currentLocation, Laplas);
		goNextLocation(startLocation, currentLocation, locAnCor[0].heroX, locAnCor[0].heroY, Laplas);
	}
}