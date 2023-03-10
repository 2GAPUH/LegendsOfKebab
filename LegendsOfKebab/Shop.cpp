#pragma once
#include "Source.h"
#include "Battle.h"

//---entity count--
#define NPC_SL 1 //SL - shop location
#define ENEMY_SL 0
//-----------------

void Shop(hero Laplas) {
	system("chcp 1251");
	char locations[5][20] = { "maps/map.txt","maps/house.txt", "maps/cave.txt", "maps/kebab_room.txt", "maps/shop.txt" };
	int startLocation = SHOP;
	int currentLocation = SHOP;
	PlaySound(L"house.wav", NULL, SND_LOOP | SND_ASYNC);
	AnLocCord locAnCor[1] = { { 59,20, 107, 8, CAVE} };
	char map[WINDOW_HEIGHT][WINDOW_WIDTH];
	Npc npcs[NPC_SL] = { {59,15} };

	GetMapFromFile(locations[currentLocation], map);
	Hero hero = {59,18};
	PrintMap(hero, map, NULL, npcs);
	while (true)
	{
		GetMapFromFile(locations[currentLocation], map);
		PrintMap(hero, map, NULL, npcs);
		heroMovement(&hero, map, Laplas);
		goNextLocation(startLocation, currentLocation, 12, 13, Laplas);
		heroColision(hero, NULL, npcs, locAnCor, currentLocation, Laplas, map);
		goNextLocation(startLocation, currentLocation, locAnCor[0].heroX, locAnCor[0].heroY, Laplas);
	}
}