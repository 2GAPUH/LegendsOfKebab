#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "Inventory.h"
#define BATTLE_WINDOW_ROWS 30
#define BATTLE_WINDOW_COLUMNS 121
#define BATTLE_COMMENTS_COUNT 30
#define BATTLE_COMMENTS_COLUMNS 365
#define FIREBALL_DAMAGE 100
#define BURNING_DAMAGE 20
#define LIGHTING_ATACK_MANA_COST 50
#define FIREBALL_MANA_COST 100
#define FIRE_RAIN_MANA_COST 20
#define STONE_WALL_MANA_COST 40

char BattleComments[BATTLE_COMMENTS_COUNT][BATTLE_COMMENTS_COLUMNS];

char HeroBattleComments[BATTLE_COMMENTS_COUNT][BATTLE_COMMENTS_COLUMNS];
char EnemyBattleComments[BATTLE_COMMENTS_COUNT][BATTLE_COMMENTS_COLUMNS];
char Events[BATTLE_COMMENTS_COUNT][BATTLE_COMMENTS_COLUMNS];
int CorretPosition_0 = 0;

struct enemy
{
	int HP, DMG, ARM;
	int Stun, Burning;
};

void GetBattleWindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], int mob)
{
	FILE* f;

	if (mob == 1)
		fopen_s(&f, "Boss.txt", "r");
		
	else if(mob == 0)
		fopen_s(&f, "Battle.txt", "r");

	else
		fopen_s(&f, "BadEnd.txt", "r");

	for (int i = 0; i < BATTLE_WINDOW_ROWS; i++)
		for (int n = 0; n < BATTLE_WINDOW_COLUMNS; n++)
			fscanf_s(f, "%c", &BattleWindow[i][n]);

	fclose(f);
}

void BattleCommentsClear(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS])
{
	for (int i = 0; i < BATTLE_COMMENTS_COLUMNS; i++)
	{
		*BattleCommentsPosition[i] = 32;

	}
	CorretPosition_0 = 0;
}


void PrintBattleWindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS])
{
	system("cls");
	for (int i = 0; i < BATTLE_WINDOW_ROWS; i++)
		for (int n = 0; n < BATTLE_WINDOW_COLUMNS; n++)
			printf_s("%c", BattleWindow[i][n]);
	BattleCommentsClear(BattleCommentsPosition);
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


void GetBattleComments()
{
	FILE* file;
	char temp;

	fopen_s(&file, "HeroBattleComments.txt", "r");

	for (int i = 0; i < BATTLE_COMMENTS_COUNT; i++)
		for (int n = 0; n < BATTLE_COMMENTS_COLUMNS; n++)
		{
			fscanf_s(file, "%c", &temp);
			HeroBattleComments[i][n] = temp;
			if (temp == '\n') break;

		}

	fclose(file);




	fopen_s(&file, "EnemyBattleComments.txt", "r");

	for (int i = 0; i < BATTLE_COMMENTS_COUNT;i++)
		for (int n = 0; n < BATTLE_COMMENTS_COLUMNS; n++)
		{
			fscanf_s(file, "%c", &temp);
			EnemyBattleComments[i][n] = temp;
			if (temp == '\n') break;

		}

	fclose(file);



	fopen_s(&file, "Events.txt", "r");

	for (int i = 0; i < BATTLE_COMMENTS_COUNT;i++)
		for (int n = 0; n < BATTLE_COMMENTS_COLUMNS; n++)
		{
			fscanf_s(file, "%c", &temp);
			Events[i][n] = temp;
			if (temp == '\n') break;

		}

	fclose(file);
}


void GetBattleCommentsPosition(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS], char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS])
{
	int n = 24, j = 45;
	for (int i = 0; i < BATTLE_COMMENTS_COLUMNS; i++, j++)
	{
		if (j == 118)
		{
			n++;
			j = 45;
		}
		BattleCommentsPosition[i] = &(BattleWindow[n][j]);
	}

}

void BattleCommentsPrint(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS], int type, char Array[BATTLE_COMMENTS_COUNT][BATTLE_COMMENTS_COLUMNS])
{
	for (int i = 0; CorretPosition_0 < BATTLE_COMMENTS_COLUMNS; CorretPosition_0++, i++)
	{
		if (Array[type][i] == '\n') break;
		*BattleCommentsPosition[CorretPosition_0] = Array[type][i];

	}
}

int FightCalculation(hero* Laplas, enemy* Kostyan, char pressedKey)
{
	//Горение
	if (Kostyan->Burning > 0)
	{
		Kostyan->Burning -= 1;
		Kostyan->HP -= BURNING_DAMAGE;
	}
	//Крит
	if (pressedKey == 32)
		Laplas->Crit += 1;
	//Сплэл стены
	if (pressedKey == '4')
	{
		Laplas->Resist = 1;
	}
	//Спэл молнии
	if (pressedKey == '1')
	{
		Kostyan->Stun = 1;
		return 0;
	}
	//Атака Костяна
	if (Laplas->Resist == 0 && Kostyan->Stun == 0)
	{
		if (Laplas->ARM < Kostyan->DMG) Laplas->HP -= (Kostyan->DMG - Laplas->ARM);
	}
	else
	{
		Laplas->Resist = 0;
		Kostyan->Stun = 0;
	}
	//Огненый шар
	if (pressedKey == '2')
	{
		Kostyan->HP -= FIREBALL_DAMAGE;
		return 0;
	}
	//Спэл поджога
	if (pressedKey == '3')
	{
		Kostyan->Burning = 2;
		Kostyan->HP -= BURNING_DAMAGE;
		return 0;
	}
	//Атака лапласа
	if (Laplas->DMG > Kostyan->ARM && Laplas->Crit < 1)
		Kostyan->HP -= (Laplas->DMG - Kostyan->ARM);
	//Крит лапласа
	if (Laplas->Crit > 0)
	{
		Laplas->Crit -= 1;
		if (rand() % 2 == 0 && Laplas->DMG > Kostyan->ARM)
			Kostyan->HP -= (Laplas->DMG - Kostyan->ARM) * 2;
	}

}




hero FightWithEnemy(hero Laplas, enemy Kostyan, char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], int seed, char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS], char* ChoiceMagic[], int mob)
{
	char pressedKey;
	int temp, tempSpel;
	

	do {
		if (mob == 0)
			PlaySound(L"fight_scene_loop.wav", NULL, SND_LOOP | SND_ASYNC);
		else
			PlaySound(L"boss_theme_loop.wav", NULL, SND_LOOP | SND_ASYNC);
		pressedKey = _getch();
		int flag = 0;


		if (pressedKey == 13)
		{
			FightCalculation(&Laplas, &Kostyan, pressedKey);
			BattleCommentsPrint(BattleCommentsPosition, 1,HeroBattleComments);
			BattleCommentsPrint(BattleCommentsPosition, 1, EnemyBattleComments);
			PlaySound(L"Atack.wav", NULL,  SND_ASYNC);
		}

		else if (pressedKey == 'q' || pressedKey == 'Q')
		{
			*ChoiceMagic[flag] = '>';
			BattleCommentsPrint(BattleCommentsPosition, 1, Events);
			PrintBattleWindow(BattleWindow, BattleCommentsPosition);
			do {
				
				pressedKey = _getch();

				if (pressedKey == 'w' && flag != 0)
				{
					flag -= 1;
					*ChoiceMagic[flag] = '>';
					*ChoiceMagic[flag + 1] = ' ';
				}
				if (pressedKey == 's' && flag != 4)
				{
					flag += 1;
					*ChoiceMagic[flag] = '>';
					*ChoiceMagic[flag - 1] = ' ';
				}
				BattleCommentsPrint(BattleCommentsPosition, 1, Events);
				PrintBattleWindow(BattleWindow, BattleCommentsPosition);
			} while (pressedKey != 13);
			
			*ChoiceMagic[flag] = ' ';
			
			if (flag != 4)
			{
				if (flag == 0 && Laplas.MP >= LIGHTING_ATACK_MANA_COST)
				{
					Laplas.MP -= LIGHTING_ATACK_MANA_COST;
					PlaySound(L"Grom.wav", NULL, SND_ASYNC);
				}
				else if (flag == 1 && Laplas.MP >= FIREBALL_MANA_COST)
				{
					Laplas.MP -= FIREBALL_MANA_COST;
					PlaySound(L"Fireball.wav", NULL, SND_ASYNC);
				}
				else if (flag == 2 && Laplas.MP >= FIRE_RAIN_MANA_COST)
				{
					Laplas.MP -= FIRE_RAIN_MANA_COST;
					PlaySound(L"Fire_rain.wav", NULL, SND_ASYNC);
				}
				else if (flag == 3 && Laplas.MP >= STONE_WALL_MANA_COST)
				{
					Laplas.MP -= STONE_WALL_MANA_COST;
					PlaySound(L"Wall.wav", NULL, SND_ASYNC);
				}
				else
				{
					PrintBattleWindow(BattleWindow, BattleCommentsPosition);
					continue;
				}
				tempSpel = FightCalculation(&Laplas, &Kostyan, pressedKey);
				//BattleCommentsPrint(BattleCommentsPosition, tempSpel);
			}
			else  
				PrintBattleWindow(BattleWindow, BattleCommentsPosition);
		}


		else if (pressedKey == 32)
		{
			FightCalculation(&Laplas, &Kostyan, pressedKey);
			PlaySound(L"Crit.wav", NULL, SND_ASYNC);
		}

		else if (pressedKey == 'e')
		{
			Inventory(Laplas, seed);
		}

		else continue;

		if (Kostyan.HP < 1) Kostyan.HP = 0;

		CheckLaplasStats(BattleWindow, Laplas);
		CheckEnemyStats(BattleWindow, Kostyan);
		PrintBattleWindow(BattleWindow, BattleCommentsPosition);
	} while (Laplas.HP > 0 && Kostyan.HP > 0);

	if (Laplas.HP <= 0)
	{
		PlaySound(L"the_end.wav", NULL,  SND_ASYNC);
		GetBattleWindow(BattleWindow, 2);
		PrintBattleWindow(BattleWindow, BattleCommentsPosition);
		pressedKey = _getch();
		exit(1);
	}

	if (Kostyan.HP <= 0 && mob == 1)
	{
		PlaySound(L"the_end.wav", NULL, SND_ASYNC);
		GetBattleWindow(BattleWindow, 2);
		PrintBattleWindow(BattleWindow, BattleCommentsPosition);
		pressedKey = _getch();
		exit(1);
	}

	return Laplas;
}




hero Battle(hero Laplas, int seed, int mob)
{
	enemy Kostyan = { 121, 17, 3 , 0, 0 };
	system("chcp 866");
	system("cls");
	if(mob == 0)
		PlaySound(L"fight_scene_loop.wav", NULL, SND_LOOP | SND_ASYNC);
	else
		PlaySound(L"boss_theme_loop.wav", NULL, SND_LOOP | SND_ASYNC);
	char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS];
	char* CommentsPosition[BATTLE_COMMENTS_COLUMNS];
	char* ChoiceMagic[5] = { &BattleWindow[24][44], &BattleWindow[25][44] , &BattleWindow[26][44] , &BattleWindow[27][44], &BattleWindow[28][44] };

	if(mob == 0)
		Kostyan = { 121, 17, 3 , 0, 0 };
	if (mob == 1)
		Kostyan = { 300, 25, 10 , 0, 0 };

	GetBattleWindow(BattleWindow, mob);
	GetBattleComments();
	GetBattleCommentsPosition(CommentsPosition, BattleWindow);

	CheckLaplasStats(BattleWindow, Laplas);
	CheckEnemyStats(BattleWindow, Kostyan);
	PrintBattleWindow(BattleWindow, CommentsPosition);


	Laplas = FightWithEnemy(Laplas, Kostyan, BattleWindow, seed, CommentsPosition, ChoiceMagic, mob);


	system("chcp 1251");
	return Laplas;
}