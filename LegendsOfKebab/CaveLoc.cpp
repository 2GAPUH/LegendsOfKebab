#pragma once
#include "Source.h"

//---entity count--
#define NPC_CL 0 //CL - cave location
#define ENEMY_CL 8
//-----------------

int nextHeroPos(int currentLoc, int startLoc) {
	if (currentLoc!=startLoc)
	{
		switch (currentLoc)
		{
		case FIRST_LOCATION:
			return 0;
			break;
		case KEBAB_ROOM:
			return 3;
			break;
		case SHOP:
			return 4;
			break;
		}
	}

	return 0;
}

void CaveLoc(int heroX, int heroY, hero Laplas) {
	system("chcp 1251");
	char locations[5][20] = { "maps/map.txt","maps/house.txt", "maps/cave.txt", "maps/shop.txt", "maps/kebab_room.txt" };
	int startLocation = CAVE;
	int currentLocation = CAVE;
	PlaySound(L"main_full.wav", NULL, SND_LOOP | SND_ASYNC);
	AnLocCord LocAnCor[3] = { { 0, 23, 118 , 23, FIRST_LOCATION},//0
								{ 120, 15, 1 , 17, KEBAB_ROOM}, //3
								{ 107,7,60,18, SHOP} };//4
	char map[WINDOW_HEIGHT][WINDOW_WIDTH];
	Enemy enemyes[ENEMY_CL] = { { 21 , 24 }, { 32, 21 }, { 46 , 16 }, { 29 , 11 }, { 54 ,10 }, { 91 , 3 }, { 89 , 21 }, { 117 , 15 } };

	GetMapFromFile(locations[currentLocation], map);
	Hero hero = { heroX,heroY };
	PrintMap(hero, map, enemyes, NULL);
	while (true)
	{
		GetMapFromFile(locations[currentLocation], map);
		PrintMap(hero, map, enemyes, NULL);
		heroMovement(&hero, map, Laplas);
		heroColision(hero, enemyes, NULL, LocAnCor, currentLocation, Laplas, map);
		goNextLocation(startLocation, currentLocation, LocAnCor[nextHeroPos(currentLocation,startLocation)].heroX, LocAnCor[nextHeroPos(currentLocation, startLocation)].heroY, Laplas);
	}
}