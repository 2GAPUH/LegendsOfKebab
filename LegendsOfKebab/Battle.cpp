#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
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
	system("cls");
	for (int i = 0; i < SIZE_OF_BATTLE_WINDOW;i++)
		printf_s("%c", BattleWindow[i]);
}

void CheckLaplasStats(char BattleWindow[], hero Laplas)
{
	BattleWindow[2464] = Laplas.HP / 100 + 48;
	BattleWindow[2465] = Laplas.HP / 10 % 10 + 48;
	BattleWindow[2466] = Laplas.HP % 10 + 48;

	BattleWindow[2586] = Laplas.MP / 100 + 48;
	BattleWindow[2587] = Laplas.MP / 10 % 10 + 48;
	BattleWindow[2588] = Laplas.MP % 10 + 48;

	BattleWindow[2709] = Laplas.DMG / 10 % 10 + 48;
	BattleWindow[2710] = Laplas.DMG % 10 + 48;

	BattleWindow[2831] = Laplas.ARM / 10 % 10 + 48;
	BattleWindow[2832] = Laplas.ARM % 10 + 48;
}

void CheckEnemyStats(char BattleWindow[], enemy unded)
{
	BattleWindow[2473] = unded.HP / 100 + 48;
	BattleWindow[2474] = unded.HP / 10 % 10 + 48;
	BattleWindow[2475] = unded.HP % 10 + 48;

	BattleWindow[2596] = unded.DMG / 10 % 10 + 48;
	BattleWindow[2597] = unded.DMG % 10 + 48;

	BattleWindow[2718] = unded.ARM / 10 % 10 + 48;
	BattleWindow[2719] = unded.ARM % 10 + 48;
}

hero UseHealthPotion(hero Laplas)
{
	int HealthPotion = 50;
	Laplas.HP += 50;
	return Laplas;
}


void FightWithEnemy(hero Laplas, enemy Kostyan, char BattleWindow[], int seed)
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
	char BattleWindow[SIZE_OF_BATTLE_WINDOW];

	enemy Kostyan = { 121, 17, 3 };

	GetBattleWindow(BattleWindow);

	CheckLaplasStats(BattleWindow,Laplas);
	CheckEnemyStats(BattleWindow, Kostyan);

	PrintBattlewindow(BattleWindow);

	FightWithEnemy(Laplas, Kostyan, BattleWindow, seed);

	return Laplas;
}