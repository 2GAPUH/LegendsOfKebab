#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#pragma comment (lib, "winmm.lib")
#include "Battle.h"
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

//-----------------------------------

void PrintMap(Hero hero, char map[WINDOW_HEIGHT][WINDOW_WIDTH], Enemy* enemyes, Npc* npcs);
void GetMapFromFile(const char* filename, char map[WINDOW_HEIGHT][WINDOW_WIDTH]);
void heroColision(Hero& main_char, Enemy* enemyes, Npc* npcs, AnLocCord* flLocAnCor, int& curLoc, hero &Laplas, char map[WINDOW_HEIGHT][WINDOW_WIDTH]);
void heroMovement(Hero* hero_char, char map[WINDOW_HEIGHT][WINDOW_WIDTH], hero &Laplas);
void goNextLocation(int firstLocation, int currentLocation, int heroEnterCoordX, int heroEnterCoordY, hero Laplas);
