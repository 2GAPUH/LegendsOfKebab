#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define BATTLE_WINDOW_ROWS 30
#define BATTLE_WINDOW_COLUMNS 121
#define BATTLE_COMMENTS_COUNT 10
#define BATTLE_COMMENTS_COLUMNS 365
#define FIREBALL_DAMAGE 100
#define BURNING_DAMAGE 20
char BattleComments[BATTLE_COMMENTS_COUNT][BATTLE_COMMENTS_COLUMNS];

struct enemy
{
	int HP, DMG, ARM;
	int Stun, Burning;
};

struct hero
{
	int HP, MP, DMG, ARM;
	int MaxHP, MaxMP;
	int Resist;
	int Crit;
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

void BattleCommentsClear(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS])
{
	for (int i = 0; i < BATTLE_COMMENTS_COLUMNS; i++)
	{
		*BattleCommentsPosition[i] = 32;

	}
}

void PrintBattleWindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS])
{
	system("cls");
	for (int i = 0; i < BATTLE_WINDOW_ROWS;i++)
		for(int n = 0; n < BATTLE_WINDOW_COLUMNS; n++)
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

hero UseHealthPotion(hero Laplas)
{
	int HealthPotion = 50;
	Laplas.HP += 50;
	if (Laplas.HP > Laplas.MaxHP) Laplas.HP = Laplas.MaxHP;
	return Laplas;
}

void GetBattleComments()
{
	FILE* file;
	char temp;

	fopen_s(&file, "BattleComments.txt", "r");

	for (int i = 0; i < BATTLE_COMMENTS_COUNT;i++)
		for (int n = 0; n < BATTLE_COMMENTS_COLUMNS; n++)
		{
			fscanf_s(file, "%c", &temp);
			BattleComments[i][n] = temp;
			if (temp == '\n') break;

		}

	fclose(file);
}


void GetBattleCommentsPosition(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS], char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS])
{
	int n = 24, j = 45;
	for (int i = 0;i < BATTLE_COMMENTS_COLUMNS; i++, j++)
	{
		if (j == 118)
		{
			n++;
			j = 45;
		}
		BattleCommentsPosition[i] = &(BattleWindow[n][j]);
	}

}

void BattleCommentsPrint(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS], int type)
{
	for (int i = 0; i < BATTLE_COMMENTS_COLUMNS; i++)
	{
		if (BattleComments[type][i] == '\n') break;
		*BattleCommentsPosition[i] = BattleComments[type][i];

	}
}

int FightCalculation(hero *Laplas, enemy *Kostyan, char pressedKey)
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
	if(pressedKey == '1')
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
		Kostyan->Burning = 3;
		return 0;
	}
	//Атака лапласа
	if (Laplas->DMG > Kostyan->ARM && Laplas->Crit < 1)
		Kostyan->HP -= (Laplas->DMG - Kostyan->ARM);
	//Крит лапласа
	if (Laplas->Crit > 0)
	{
		Laplas->Crit -= 1;
		if (rand() % 2  == 0 && Laplas->DMG > Kostyan->ARM)
			Kostyan->HP -= (Laplas->DMG - Kostyan->ARM)* 2;
	}

}


void FightWithEnemy(hero Laplas, enemy Kostyan, char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], int seed, char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS])
{
	char pressedKey;
	int temp, tempSpel;


	do {
		pressedKey = _getch();
		
		system("color 0F");
		Sleep(50);
		system("color F0");

		if (pressedKey == 13)
		{
			FightCalculation(&Laplas, &Kostyan, pressedKey);
			BattleCommentsPrint(BattleCommentsPosition, 1);
		}

		else if (pressedKey == 'q' || pressedKey == 'Q' || pressedKey == 137 || pressedKey == 169)
		{
			BattleCommentsPrint(BattleCommentsPosition, 7);
			PrintBattleWindow(BattleWindow, BattleCommentsPosition);
			pressedKey = _getch();
			
			if (pressedKey == '1' || pressedKey == '2' || pressedKey == '3' || pressedKey == '4')
			{
				tempSpel = FightCalculation(&Laplas, &Kostyan, pressedKey);
				//BattleCommentsPrint(BattleCommentsPosition, tempSpel);
			}
			else if (pressedKey == '0') 
				PrintBattleWindow(BattleWindow, BattleCommentsPosition);;
		}

		else if (pressedKey == 'e' || pressedKey == 'E')
		{
			FightCalculation(&Laplas, &Kostyan, pressedKey);
		}

		else if (pressedKey == 32)
		{
			FightCalculation(&Laplas, &Kostyan, pressedKey);
		}

		else continue;
		
		if (Kostyan.HP < 1) Kostyan.HP = 0;

		CheckLaplasStats(BattleWindow, Laplas);
		CheckEnemyStats(BattleWindow, Kostyan);
		PrintBattleWindow(BattleWindow, BattleCommentsPosition);
	}while(Laplas.HP > 0 && Kostyan.HP > 0);

}




hero Battle(hero Laplas, int seed)
{
	char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS];
	char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS];

	enemy Kostyan = { 121, 17, 3 , 0, 0};

	GetBattleWindow(BattleWindow);
	GetBattleComments();
	GetBattleCommentsPosition(BattleCommentsPosition, BattleWindow);

	CheckLaplasStats(BattleWindow,Laplas);
	CheckEnemyStats(BattleWindow, Kostyan);
	PrintBattleWindow(BattleWindow, BattleCommentsPosition);


	FightWithEnemy(Laplas, Kostyan, BattleWindow, seed, BattleCommentsPosition);

	return Laplas;
}