#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "Battle.h"

#pragma comment (lib, "winmm.lib")


//---window properties-�
#define WINDOW_HEIGHT 30
#define WINDOW_WIDTH 122
//---------------------�

//---location id-�
#define FIRST_LOCATION 0
#define HOUSE 1
//-------------��

//---items id---�
#define HEAL_POTION 1
#define DAMAGE_POTION 2
#define MANA_POTION 3
#define ARMOR_POTION 4
#define KEBAB 5
//--------------�

//---entity count--
#define NPC_FL 1 //FL - first location
#define ENEMY_FL 1
//-----------------

//----entity id---
#define ENEMY 0
#define NPC 1
//----------------

//---------structures--------------
struct HeroMap
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
};

//-----------------------------------

void PrintMap(HeroMap hero, char map[WINDOW_HEIGHT][WINDOW_WIDTH], Enemy enemyes[ENEMY_FL], Npc npcs[NPC_FL])
{
	system("cls");
	for (int i = 0; i < WINDOW_HEIGHT; i++)
		for (int n = 0; n < WINDOW_WIDTH; n++) {
			if (hero.y == i && hero.x == n)
			{
				printf_s("@");
			}
			else if (enemyes[0].y == i && enemyes[0].x == n)
			{
				printf_s("/");
			}
			else if (npcs[0].y == i && npcs[0].x == n)
			{
				printf_s("$");
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

void heroColision(HeroMap hero1, Enemy enemyes[ENEMY_FL], Npc npcs[NPC_FL]) {
	hero Laplas1 = { 234, 61, 27, 3, 250, 100, 0, 0 };
	if (hero1.x == enemyes[0].x && hero1.y == enemyes[0].y)
	{
		Battle(Laplas1, 123);
	}
	else if (hero1.x == npcs[0].x && hero1.y == npcs[0].y)
	{
		//open shop
	}
}

void heroMovement(HeroMap* hero, char map[WINDOW_HEIGHT][WINDOW_WIDTH]) {
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



int map() {
	system("chcp 1251");
	char locations[2][20] = { "maps/map.txt","maps/house.txt" };
	int currentLocation = FIRST_LOCATION;
	PlaySound(L"main_full.wav", NULL, SND_LOOP | SND_ASYNC);
	char map[WINDOW_HEIGHT][WINDOW_WIDTH];
	Enemy enemyes[ENEMY_FL] = { {7 , 20} };
	Npc npcs[NPC_FL] = { {6,25} };

	GetMapFromFile(locations[currentLocation], map);
	HeroMap hero1 = { 10,25 };
	PrintMap(hero1, map, enemyes, npcs);
	while (true)
	{
		PrintMap(hero1, map, enemyes, npcs);
		heroMovement(&hero1, map);
		heroColision(hero1,enemyes,npcs);
	}

	system("pause");
	return 0;
}