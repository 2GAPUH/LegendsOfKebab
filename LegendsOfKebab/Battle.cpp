#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE_OF_BATTLE_WINDOW 3068

struct hero
{
	int HP, MP, DMG, ARM;
};

struct enemy
{
	int HP, DMG, ARM;
};


void GetBattleWindow(char BattleWindow[])
{
	FILE* f;

	fopen_s(&f, "Battle.txt", "r");

	for (int i = 0; i < SIZE_OF_BATTLE_WINDOW; i++)
		fscanf_s(f, "%c", &BattleWindow[i]);

	fclose(f);
}

void PrintBattlewindow(char BattleWindow[])
{
	for (int i = 0; i < SIZE_OF_BATTLE_WINDOW;i++)
		printf_s("%c", BattleWindow[i]);
}

void FightWithEnemy()
{

}

void Battle()
{


	char BattleWindow[SIZE_OF_BATTLE_WINDOW];

	GetBattleWindow(BattleWindow);

	PrintBattlewindow(BattleWindow);

	FightWithEnemy();
}