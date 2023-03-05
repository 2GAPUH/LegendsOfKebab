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
	int MaxHP, MaxMP;
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
	BattleWindow[25][5] = Laplas.HP / 100 + 48;
	BattleWindow[25][6] = Laplas.HP / 10 % 10 + 48;
	BattleWindow[25][7] = Laplas.HP % 10 + 48;

	BattleWindow[26][5] = Laplas.MP / 100 + 48;
	BattleWindow[26][6] = Laplas.MP / 10 % 10 + 48;
	BattleWindow[26][7] = Laplas.MP % 10 + 48;

	BattleWindow[27][6] = Laplas.DMG / 10 % 10 + 48;
	BattleWindow[27][7] = Laplas.DMG % 10 + 48;

	BattleWindow[28][6] = Laplas.ARM / 10 % 10 + 48;
	BattleWindow[28][7] = Laplas.ARM % 10 + 48;
}

void CheckEnemyStats(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], enemy unded)
{
	BattleWindow[25][14] = unded.HP / 100 + 48;
	BattleWindow[25][15] = unded.HP / 10 % 10 + 48;
	BattleWindow[25][16] = unded.HP % 10 + 48;

	BattleWindow[26][15] = unded.DMG / 10 % 10 + 48;
	BattleWindow[26][16] = unded.DMG % 10 + 48;

	BattleWindow[27][15] = unded.ARM / 10 % 10 + 48;
	BattleWindow[27][16] = unded.ARM % 10 + 48;
}

hero UseHealthPotion(hero Laplas)
{
	int HealthPotion = 50;
	Laplas.HP += 50;
	if (Laplas.HP > Laplas.MaxHP) Laplas.HP = Laplas.MaxHP;
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

		else if (pressedKey == 'q' || pressedKey == 'Q' || pressedKey == '�' || pressedKey == '�')
		{
			Laplas = UseHealthPotion(Laplas);
			if ((temp = Kostyan.DMG - Laplas.ARM) > 0) Laplas.HP -= temp;
		}

		else if (pressedKey == 32)
		{
			if (rand() % 2 == 0)
				if ((temp = Laplas.DMG*2 - Kostyan.ARM) > 0) Kostyan.HP -= temp;
			
			if ((temp = Kostyan.DMG - Laplas.ARM) > 0) Laplas.HP -= temp;
		}

		else continue;
		
		if (Kostyan.HP < 1) Kostyan.HP = 0;

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