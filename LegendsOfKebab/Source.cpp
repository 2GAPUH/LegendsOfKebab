#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "FirstLoc.h"
#include "HouseLoc.h"
#include "Trader.h"
#include "CaveLoc.h"
#include "KebabLoc.h"
#include "Battle.h"
#include "Shop.h"
#include "Trader.h"


#pragma comment (lib, "winmm.lib")

//---window properties-—
#define WINDOW_HEIGHT 30
#define WINDOW_WIDTH 122
//---------------------—

//---location id-—
#define FIRST_LOCATION 0
#define HOUSE 1
#define CAVE 2
#define KEBAB_ROOM 3
#define SHOP 4
//-------------——

//---items id---—
#define HEAL_POTION 1
#define DAMAGE_POTION 2
#define MANA_POTION 3
#define ARMOR_POTION 4
#define KEBAB 5
//--------------—

//---entity count--
#define NPC_FL 1 //FL - first location
#define ENEMY_FL 1
//-----------------

//----entity id---
#define ENEMY 0
#define NPC 1
//----------------

//---------structures--------------
struct Hero
{
	int x;
	int y;
	//int inventory[6] = {0};
};

struct Enemy
{
	int x;
	int y;
};

struct Npc
{
	int x;
	int y;
};

struct AnLocCord //another locations coordinates
{
	int x;
	int y;
	int heroX;
	int heroY;
	int location;
};

struct EnterNewLocCord
{
	int heroX;
	int heroY;
};

//-----------------------------------

void PrintMap(Hero hero, char map[WINDOW_HEIGHT][WINDOW_WIDTH], Enemy* enemyes, Npc* npcs)
{
	system("cls");
	for (int i = 0; i < WINDOW_HEIGHT; i++)
		for (int n = 0; n < WINDOW_WIDTH; n++) {
			if (enemyes != NULL)
			{
			for (int ec = 0; ec < sizeof(enemyes); ec++) // ec - enemy count
			{
				if (enemyes[ec].y == i && enemyes[ec].x == n)
				{
					map[i][n] = '¤';
				}
			}
			}
		}
	for (int i = 0; i < WINDOW_HEIGHT; i++)
		for (int n = 0; n < WINDOW_WIDTH; n++) {
			if (npcs != NULL)
			{
				for (int nc = 0; nc < sizeof(npcs); nc++) // nc - npc count
				{
					if (npcs[nc].y == i && npcs[nc].x == n)
					{
						map[i][n] = '$';
					}
				}
			}
		}

	for (int i = 0; i < WINDOW_HEIGHT; i++)
		for (int n = 0; n < WINDOW_WIDTH; n++) {
			if (hero.y == i && hero.x == n)
			{
				printf_s("@");
			}
			else {
				printf_s("%c", map[i][n]);
			}
		}
}

void GetMapFromFile(const char* filename, char map[WINDOW_HEIGHT][WINDOW_WIDTH])
{
	FILE* f;

	fopen_s(&f, filename, "r");

	for (int i = 0; i < WINDOW_HEIGHT; i++)
		for (int n = 0; n < WINDOW_WIDTH; n++)
			fscanf_s(f, "%c", &map[i][n]);
	fclose(f);
}

void heroColision(Hero &main_char, Enemy *enemyes, Npc* npcs, AnLocCord* anLocCor, int &curLoc, hero &Laplas) {
	if (enemyes != NULL) {
		for (int i = 0; i < sizeof(enemyes); i++)
		{
			if (main_char.x == enemyes[i].x && main_char.y == enemyes[i].y)
			{
				enemyes[i].x = -1;
				Laplas = Battle(Laplas, 10);

			}
		}
	}

	if (npcs != NULL) {
		for (int i = 0; i < 1; i++)
		{
			if (main_char.x == npcs[i].x && main_char.y == npcs[i].y)
			{
				Trade(Laplas, 10);
			}
		}
	}
	if ((curLoc == KEBAB_ROOM) && (main_char.x == 70 && main_char.y == 17))
	{
		//final battle
	}
	
	
	for (int i = 0; i < sizeof(anLocCor); i++)
	{
		if (main_char.x == anLocCor[i].x && main_char.y == anLocCor[i].y)
			{
				main_char.x = anLocCor[i].heroX;
				main_char.y = anLocCor[i].heroY;
				curLoc = anLocCor[i].location;
			}
	}
}

void heroMovement(Hero* hero, char map[WINDOW_HEIGHT][WINDOW_WIDTH]) {
	char inputButton = _getch();
	switch (inputButton)
	{
	case 'w':
		if (map[(hero->y) - 1][hero->x] != '#')
		{
			hero->y--;
		}
		break;
	case 'a':
		if (map[hero->y][(hero->x) - 1] != '#')
		{
			hero->x--;
		}
		break;
	case 's':
		if (map[(hero->y) + 1][hero->x] != '#')
		{
			hero->y++;
		}
		break;
	case 'd':
		if (map[hero->y][(hero->x) + 1] != '#')
		{
			hero->x++;
		}
		break;
	}
}

void goNextLocation(int firstLocation,int currentLocation, int heroEnterCoordX, int heroEnterCoordY, hero Laplas) {
	if (firstLocation != currentLocation)
	{
		switch (currentLocation)
		{
		case FIRST_LOCATION:
			FirstLoc(heroEnterCoordX, heroEnterCoordY, Laplas);
			break;
		case HOUSE:
			House(Laplas);
			break;
		case CAVE:
			CaveLoc(heroEnterCoordX, heroEnterCoordY, Laplas);
			break;
		case SHOP:
			Shop(Laplas);
			break;
		case KEBAB_ROOM:
			Kebab(Laplas);
			break;
		}
	}
}
