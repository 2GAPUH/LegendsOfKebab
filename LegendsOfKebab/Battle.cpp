#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#define BATTLE_WINDOW_ROWS 30
#define BATTLE_WINDOW_COLUMNS 121


struct enemy
{
	int HP, DMG, ARM;
};

struct hero
{
	int HP, MP, DMG, ARM;
};



void GetBattleWindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS])
{
	FILE* f;

	fopen_s(&f, "Battle.txt", "r");

	for (int i = 0; i < BATTLE_WINDOW_ROWS;i++)
		for (int n = 0; n < BATTLE_WINDOW_COLUMNS; n++)
			fscanf_s(f, "%c", &BattleWindow[i][n]);

	fclose(f);
}

void PrintBattlewindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS])
{
	system("cls");
	for (int i = 0; i < BATTLE_WINDOW_ROWS;i++)
		for(int n = 0; n < BATTLE_WINDOW_COLUMNS; n++)
			printf_s("%c", BattleWindow[i][n]);
}

void CheckLaplasStats(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], hero Laplas)
{
	BattleWindow[20][31] = Laplas.HP / 100 + 48;
	BattleWindow[20][31] = Laplas.HP / 10 % 10 + 48;
	BattleWindow[20][31] = Laplas.HP % 10 + 48;

	BattleWindow[20][31] = Laplas.MP / 100 + 48;
	BattleWindow[20][31] = Laplas.MP / 10 % 10 + 48;
	BattleWindow[20][31] = Laplas.MP % 10 + 48;

	BattleWindow[20][31] = Laplas.DMG / 10 % 10 + 48;
	BattleWindow[20][31] = Laplas.DMG % 10 + 48;

	BattleWindow[20][31] = Laplas.ARM / 10 % 10 + 48;
	BattleWindow[20][31] = Laplas.ARM % 10 + 48;
}

void CheckEnemyStats(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], enemy unded)
{
	BattleWindow[20][31] = unded.HP / 100 + 48;
	BattleWindow[20][31] = unded.HP / 10 % 10 + 48;
	BattleWindow[20][31] = unded.HP % 10 + 48;

	BattleWindow[20][31] = unded.DMG / 10 % 10 + 48;
	BattleWindow[20][31] = unded.DMG % 10 + 48;

	BattleWindow[20][31] = unded.ARM / 10 % 10 + 48;
	BattleWindow[20][31] = unded.ARM % 10 + 48;
}

hero UseHealthPotion(hero Laplas)
{
	int HealthPotion = 50;
	Laplas.HP += 50;
	return Laplas;
}


void FightWithEnemy(hero Laplas, enemy Kostyan, char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], int seed)
{
	char pressedKey;
	int temp;

	do {
		pressedKey = _getch();
		
		if (pressedKey == 13)
		{
			if ((temp = Kostyan.DMG - Laplas.ARM) > 0) Laplas.HP -= temp;
			if ((temp = Laplas.DMG - Kostyan.ARM) > 0) Kostyan.HP -= temp;
		}

		else if (pressedKey == 'q' || pressedKey == 'Q' || pressedKey == 'é' || pressedKey == 'É')
		{
			Laplas = UseHealthPotion(Laplas);
			if ((temp = Kostyan.DMG - Laplas.ARM) > 0) Laplas.HP -= temp;
		}

		/*if (pressedKey == 32)
		{
			if (rand() % 2 == 0)
			{
				if ((temp = Kostyan.DMG - Laplas.ARM) > 0) Laplas.HP -= temp;
			}
			else distance = 1;
		}*/

		else continue;
		
		CheckLaplasStats(BattleWindow, Laplas);
		CheckEnemyStats(BattleWindow, Kostyan);
		PrintBattlewindow(BattleWindow);
	}while(Laplas.HP > 0 && Kostyan.HP > 0);

}




hero Battle(hero Laplas, int seed)
{
	char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS];

	enemy Kostyan = { 121, 17, 3 };

	GetBattleWindow(BattleWindow);

	CheckLaplasStats(BattleWindow,Laplas);
	CheckEnemyStats(BattleWindow, Kostyan);

	PrintBattlewindow(BattleWindow);

	FightWithEnemy(Laplas, Kostyan, BattleWindow, seed);

	return Laplas;
}