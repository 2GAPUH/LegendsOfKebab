#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <conio.h>


#define INVENTORY_WINDOW_ROWS 29
#define INVENTORY_WINDOW_COLUMNS 120
#define INVENTORY_COMMENTS_COUNT 29
#define INVENTORY_COMMENTS_COLUMNS 234
#define DESC_WINDOW 234
#define OBJ_WINDOW 156
#define OBJ_HEIGHT 6
#define OBJ_WIDTH 27
#define DESC_HEIGHT 6
#define DESC_WIDTH 40
#define HealthPotion 100
#define ManaPotion 50

char description[DESC_HEIGHT][DESC_WIDTH];
char InventoryComments[INVENTORY_COMMENTS_COUNT][INVENTORY_COMMENTS_COLUMNS];
char objects[OBJ_HEIGHT][OBJ_WIDTH];
int CorretPosition = 0;
int CorPosition0 = 0;
int CorPosition1 = 0;

struct hero
{
	int HP, MP, DMG, ARM, MON;
	int MaxHP, MaxMP;
	int Resist;
	int Crit;
	int Invent[6];
};

struct cost
{
	int cost1, cost2, cost3, cost4, cost5;
};

hero UseHealthPotion(hero Laplas)
{
	Laplas.HP += 100;
	if (Laplas.HP > Laplas.MaxHP) Laplas.HP = Laplas.MaxHP;
	return Laplas;
}

hero UseManaPotion(hero Laplas)
{
	Laplas.MP += 50;
	if (Laplas.MP > Laplas.MaxMP) Laplas.MP = Laplas.MaxMP;
	return Laplas;
}

hero UseKebab(hero Laplas)
{
	Laplas.HP += 75;
	Laplas.MP += 75;
	if (Laplas.HP > Laplas.MaxHP) Laplas.HP = Laplas.MaxHP;
	if (Laplas.MP > Laplas.MaxMP) Laplas.MP = Laplas.MaxMP;
	return Laplas;
}

void InventoryClear(char* array[])
{
	for (int i = 0; i < DESC_WINDOW; i++)
	{
		*array[i] = 32;

	}
	CorPosition1 = 0;
	CorPosition0 = 0;
}


void GetObjectPosition(char* ar_position[OBJ_WINDOW], char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS])
{
	int n = 22, j = 49;
	for (int i = 0; i < OBJ_WINDOW; i++, j++)
	{
		if (j == 75)
		{
			n++;
			j = 49;
		}
		ar_position[i] = &(InventoryWindow[n][j]);
	}
}

void GetDescriptionPosition(char* ar_position[DESC_WINDOW], char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS])
{
	int n = 22, j = 79;
	for (int i = 0; i < DESC_WINDOW; i++, j++)
	{
		if (j == 118)
		{
			n++;
			j = 79;
		}
		ar_position[i] = &(InventoryWindow[n][j]);
	}

}

void GetInventoryWindow(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS])
{
	FILE* f;

	fopen_s(&f, "Inventory.txt", "r");

	for (int i = 0; i < INVENTORY_WINDOW_ROWS; i++)
		for (int n = 0; n < INVENTORY_WINDOW_COLUMNS; n++)
			fscanf_s(f, "%c", &InventoryWindow[i][n]);

	fclose(f);
}

void GetObjects()
{
	FILE* f;
	if (fopen_s(&f, "Items.txt", "rt") == 0)
	{
		for (int i = 0; i < OBJ_HEIGHT; i++)
			for (int j = 0; j < OBJ_WIDTH; j++)
				fscanf_s(f, "%c", &objects[i][j]);
		fclose(f);
	}
	else
	{
		printf("Can't load the level!");
		exit(1);
	}
}

void GetInventoryComments()
{
	FILE* file;
	char temp;

	fopen_s(&file, "TradeComments.txt", "r");

	for (int i = 0; i < INVENTORY_COMMENTS_COUNT; i++)
		for (int n = 0; n < INVENTORY_COMMENTS_COLUMNS; n++)
		{
			fscanf_s(file, "%c", &temp);
			InventoryComments[i][n] = temp;
			if (temp == '\n') break;

		}

	fclose(file);
}

void InventoryCommentsClear(char* TradeCommentsPosition[INVENTORY_COMMENTS_COLUMNS])
{
	for (int i = 0; i < INVENTORY_COMMENTS_COLUMNS; i++)
	{
		*TradeCommentsPosition[i] = 32;

	}
	CorretPosition = 0;

}


void GetInventoryCommentsPosition(char* TradeCommentsPosition[INVENTORY_COMMENTS_COLUMNS], char TradeWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS])
{
	int n = 22, j = 78;
	for (int i = 0; i < INVENTORY_COMMENTS_COLUMNS; i++, j++)
	{
		if (j == 117)
		{
			n++;
			j = 78;
		}
		TradeCommentsPosition[i] = &(TradeWindow[n][j]);
	}

}


void InventoryCommentsPrint(char* TradeCommentsPosition[INVENTORY_COMMENTS_COLUMNS], int type, char Array[INVENTORY_COMMENTS_COUNT][INVENTORY_COMMENTS_COLUMNS])
{
	for (int i = 0; CorretPosition < INVENTORY_COMMENTS_COLUMNS; CorretPosition++, i++)
	{
		if (Array[type][i] == '\n') break;
		*TradeCommentsPosition[CorretPosition] = Array[type][i];

	}
}

void GetDescription()
{
	FILE* f;
	if (fopen_s(&f, "DescriptionItems.txt", "rt") == 0)
	{
		for (int i = 0; i < DESC_HEIGHT; i++)
			for (int j = 0; j < DESC_WIDTH; j++)
				fscanf_s(f, "%c", &description[i][j], 1);
		fclose(f);
	}
	else
	{
		printf("Can't load the level!");
		exit(1);
	}
}


void InventoryObjectPrint(char* ar_position[OBJ_WINDOW], int type)
{
	for (int i = 0; CorPosition0 < OBJ_WINDOW; CorPosition0++, i++)
	{
		if (objects[type][i] == '\n') break;
		*ar_position[CorPosition0] = objects[type][i];

	}
}

void InventoryDescriptionPrint(char* ar_position[DESC_WINDOW], int type)
{
	for (int i = 0; CorPosition1 < DESC_WINDOW; CorPosition1++, i++)
	{
		if (description[type][i] == '\n') break;
		*ar_position[CorPosition1] = description[type][i];

	}
}


void PrintInventoryWindow(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS])
{
	system("cls");
	for (int i = 0; i < INVENTORY_WINDOW_ROWS; i++)
		for (int n = 0; n < INVENTORY_WINDOW_COLUMNS; n++)
			printf_s("%c", InventoryWindow[i][n]);
}

void CheckLaplasInvStats(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS], hero Laplas)
{

	InventoryWindow[23][6] = Laplas.DMG / 100 + 48;
	InventoryWindow[23][7] = Laplas.DMG / 10 % 10 + 48;
	InventoryWindow[23][8] = Laplas.DMG % 10 + 48;

	InventoryWindow[24][5] = Laplas.HP / 100 + 48;
	InventoryWindow[24][6] = Laplas.HP / 10 % 10 + 48;
	InventoryWindow[24][7] = Laplas.HP % 10 + 48;

	InventoryWindow[25][5] = Laplas.MP / 100 + 48;
	InventoryWindow[25][6] = Laplas.MP / 10 % 10 + 48;
	InventoryWindow[25][7] = Laplas.MP % 10 + 48;

	InventoryWindow[26][6] = Laplas.ARM / 100 + 48;
	InventoryWindow[26][7] = Laplas.ARM / 10 % 10 + 48;
	InventoryWindow[26][8] = Laplas.ARM % 10 + 48;

	InventoryWindow[27][6] = Laplas.MON / 1000 + 48;
	InventoryWindow[27][7] = Laplas.MON / 100 % 10 + 48;
	InventoryWindow[27][8] = Laplas.MON / 10 % 10 + 48;
	InventoryWindow[27][9] = Laplas.MON % 10 + 48;
}

void CheckCountObjects(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS], hero Laplas)
{
	InventoryWindow[22][45] = Laplas.Invent[0] / 10 % 10 + 48;;
	InventoryWindow[22][46] = Laplas.Invent[0] % 10 + 48;

	InventoryWindow[23][45] = Laplas.Invent[1] / 10 % 10 + 48;;
	InventoryWindow[23][46] = Laplas.Invent[1] % 10 + 48;

	InventoryWindow[24][45] = Laplas.Invent[2] / 10 % 10 + 48;;
	InventoryWindow[24][46] = Laplas.Invent[2] % 10 + 48;

	InventoryWindow[25][46] = Laplas.Invent[3] % 10 + 48;

	InventoryWindow[26][45] = Laplas.Invent[4] / 10 % 10 + 48;;
	InventoryWindow[26][46] = Laplas.Invent[4] % 10 + 48;

	InventoryWindow[27][45] = Laplas.Invent[5] / 10 % 10 + 48;;
	InventoryWindow[27][46] = Laplas.Invent[5] % 10 + 48;

}

void MovingInventory(char* choice_obj[], char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS], char* description_position[DESC_WINDOW], char* InventoryCommentsPosition[INVENTORY_WINDOW_ROWS], hero &Laplas) {
	char btn =0;
	int flag = 0;
	*choice_obj[flag] = '>';
	InventoryDescriptionPrint(description_position, flag);
	CheckLaplasInvStats(InventoryWindow, Laplas);
	PrintInventoryWindow(InventoryWindow);
	InventoryClear(description_position);
	while  (btn != 9)
	{
		do {
			btn = _getch();
		} while (btn != 's' && btn != 'w' && btn != 'S' && btn != 'W' && btn != 13 && btn != 9 && btn != '=');

		if (btn == '=')
		{
			if (_getch() == 'k')
				if (_getch() == 'e')
					if (_getch() == 'b')
						if (_getch() == 'a')
							if (_getch() == 'b')
								Laplas.MON = 9999;
		}

		if ((btn == 'w' || btn == 'W') && flag != 0)
		{
			flag -= 1;
			*choice_obj[flag] = '>';
			*choice_obj[flag + 1] = ' ';
		}
		if ((btn == 's' || btn == 'S')&& flag != 5)
		{
			flag += 1;
			*choice_obj[flag] = '>';
			*choice_obj[flag - 1] = ' ';
		}
		if (btn == 13 && flag == 0)
		{
			if (Laplas.Invent[0] >= 1)
			{
				Laplas = UseHealthPotion(Laplas);
				Laplas.Invent[0] -= 1;
				CheckCountObjects(InventoryWindow, Laplas);
			}
			else
			{
				InventoryCommentsPrint(InventoryCommentsPosition, 23, InventoryComments);
				PrintInventoryWindow(InventoryWindow);
				InventoryCommentsClear(InventoryCommentsPosition);
				do {
					btn = _getch();
				} while (btn != 13);
			}
		}
		if (btn == 13 && flag == 1)
		{
			if (Laplas.Invent[1] >= 1)
			{
				Laplas = UseManaPotion(Laplas);
				Laplas.Invent[1] -= 1;
				CheckCountObjects(InventoryWindow, Laplas);
			}
			else
			{
				InventoryCommentsPrint(InventoryCommentsPosition, 23, InventoryComments);
				PrintInventoryWindow(InventoryWindow);
				InventoryCommentsClear(InventoryCommentsPosition);
				do {
					btn = _getch();
				} while (btn != 13);
			}
		}
		if (btn == 13 && flag == 2)
		{
			if (Laplas.Invent[2] >= 1)
			{
				Laplas = UseKebab(Laplas);
				Laplas.Invent[2] -= 1;
				CheckCountObjects(InventoryWindow, Laplas);
			}
			else
			{
				InventoryCommentsPrint(InventoryCommentsPosition, 23, InventoryComments);
				PrintInventoryWindow(InventoryWindow);
				InventoryCommentsClear(InventoryCommentsPosition);
				do {
					btn = _getch();
				} while (btn != 13);
			}
		}
		if (btn == 13 && flag == 3)
		{
			InventoryCommentsPrint(InventoryCommentsPosition, 24, InventoryComments);
			PrintInventoryWindow(InventoryWindow);
			InventoryCommentsClear(InventoryCommentsPosition);
			do {
				btn = _getch();
			} while (btn != 13);
		}
		InventoryDescriptionPrint(description_position, flag);
		CheckLaplasInvStats(InventoryWindow, Laplas);
		PrintInventoryWindow(InventoryWindow);
		InventoryClear(description_position);
	}
	*choice_obj[flag] = ' ';
}




hero Inventory(hero &Laplas, int seed)
{
	system("chcp 866");
	PlaySound(L"main_loop.wav", NULL, SND_LOOP | SND_ASYNC);
	char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS];
	char* InventoryCommentsPosition[INVENTORY_COMMENTS_COLUMNS];
	char* object_position[OBJ_WINDOW];
	char* description_position[DESC_WINDOW];
	char  pressedKey;
	char* choice_obj[6] = { &InventoryWindow[22][44], &InventoryWindow[23][44] , &InventoryWindow[24][44] , &InventoryWindow[25][44], &InventoryWindow[26][44], &InventoryWindow[27][44] };

	GetInventoryWindow(InventoryWindow);
	GetObjectPosition(object_position, InventoryWindow);
	GetDescriptionPosition(description_position, InventoryWindow);
	GetObjects();
	GetDescription();
	GetInventoryComments();
	GetInventoryCommentsPosition(InventoryCommentsPosition, InventoryWindow);
	CheckLaplasInvStats(InventoryWindow, Laplas);
	CheckCountObjects(InventoryWindow, Laplas);
	for (int i = 0; i < 6; i++)
		InventoryObjectPrint(object_position, i);
	MovingInventory(choice_obj, InventoryWindow, description_position, InventoryCommentsPosition, Laplas);

	system("chcp 1251");
	return Laplas;
}
