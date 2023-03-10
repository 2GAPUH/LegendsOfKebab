#pragma once
#include "Source.h"
#include "Battle.h"




//---entity count--
#define NPC_FL 0 //FL - first location
#define ENEMY_FL 6
//-----------------


void FirstLoc(int heroX, int heroY, hero Laplas) {
	system("chcp 1251");
	char locations[5][20] = { "maps/map.txt","maps/house.txt", "maps/cave.txt", "maps/shop.txt", "maps/kebab_room.txt" };
	int startLocation = FIRST_LOCATION;
	int currentLocation = FIRST_LOCATION;
	PlaySound(L"main_full.wav", NULL, SND_LOOP | SND_ASYNC);
	AnLocCord LocAnCor[2] = { { 13,10, 59 , 17, HOUSE},
								{ 120,23, 3, 23, CAVE} };
	char map[WINDOW_HEIGHT][WINDOW_WIDTH];
	Enemy enemyes[ENEMY_FL] = { {113,23}, {28,15}, {66,26}, {95,15}, {85,9}, {96,7} };
	GetMapFromFile(locations[currentLocation], map);
	Hero hero = { heroX,heroY };// 10, 25
	PrintMap(hero, map, enemyes, NULL);
	while (true)
	{
		GetMapFromFile(locations[currentLocation], map);
		PrintMap(hero, map, enemyes, NULL);
		heroMovement(&hero, map, Laplas);
		heroColision(hero, enemyes, NULL, LocAnCor, currentLocation, Laplas,map);
		goNextLocation(startLocation,currentLocation, LocAnCor[currentLocation-1].heroX, LocAnCor[currentLocation - 1].heroY, Laplas);
	}
}