#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE_OF_BATTLE_WINDOW 3068



struct enemy
{
	int HP, DMG, ARM;
};

struct hero
{
	int HP, MP, DMG, ARM;
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

void CheckStats(char BattleWindow[], hero Laplas)
{
	BattleWindow[2467] = Laplas.HP / 100 + 48;
	BattleWindow[2468] = Laplas.HP / 10 % 10 + 48;
	BattleWindow[2469] = Laplas.HP % 10 + 48;

	BattleWindow[2589] = Laplas.MP / 100 + 48;
	BattleWindow[2590] = Laplas.MP / 10 % 10 + 48;
	BattleWindow[2591] = Laplas.MP % 10 + 48;

	BattleWindow[2712] = Laplas.DMG / 10 % 10 + 48;
	BattleWindow[2713] = Laplas.DMG % 10 + 48;

	BattleWindow[2834] = Laplas.ARM / 10 % 10 + 48;
	BattleWindow[2835] = Laplas.ARM % 10 + 48;
}

void FightWithEnemy()
{

}

hero Battle(hero Laplas)
{
	char BattleWindow[SIZE_OF_BATTLE_WINDOW];

	GetBattleWindow(BattleWindow);

	CheckStats(BattleWindow,Laplas);

	PrintBattlewindow(BattleWindow);

	FightWithEnemy();

	return Laplas;
}