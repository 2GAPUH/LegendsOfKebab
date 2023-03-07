#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <conio.h>

#define INVENTORY_WINDOW_ROWS 30
#define INVENTORY_WINDOW_COLUMNS 120

struct hero
{
	int HP, MP, DMG, ARM, MON;
	int MaxHP, MaxMP;
	int Resist;
	int Crit;
};

struct cost
{
	int cost1, cost2, cost3, cost4, cost5;
};



void GetInventoryWindow(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS])
{
	FILE* f;

	fopen_s(&f, "Inventory.txt", "r");

	for (int i = 0; i < INVENTORY_WINDOW_ROWS; i++)
		for (int n = 0; n < INVENTORY_WINDOW_COLUMNS; n++)
			fscanf_s(f, "%c", &InventoryWindow[i][n]);

	fclose(f);
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

	InventoryWindow[24][6] = Laplas.DMG / 100 + 48;
	InventoryWindow[24][7] = Laplas.DMG / 10 % 10 + 48;
	InventoryWindow[24][8] = Laplas.DMG % 10 + 48;

	InventoryWindow[25][5] = Laplas.HP / 100 + 48;
	InventoryWindow[25][6] = Laplas.HP / 10 % 10 + 48;
	InventoryWindow[25][7] = Laplas.HP % 10 + 48;

	InventoryWindow[26][5] = Laplas.MP / 100 + 48;
	InventoryWindow[26][6] = Laplas.MP / 10 % 10 + 48;
	InventoryWindow[26][7] = Laplas.MP % 10 + 48;

	InventoryWindow[27][6] = Laplas.ARM / 100 + 48;
	InventoryWindow[27][7] = Laplas.ARM / 10 % 10 + 48;
	InventoryWindow[27][8] = Laplas.ARM % 10 + 48;

	InventoryWindow[28][6] = Laplas.MON / 1000 + 48;
	InventoryWindow[28][7] = Laplas.MON / 100 % 10 + 48;
	InventoryWindow[28][8] = Laplas.MON / 10 % 10 + 48;
	InventoryWindow[28][9] = Laplas.MON % 10 + 48;
}

void InventoryMas()
{

}

hero Inventory(hero Laplas, int seed)
{
	char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS];

	GetInventoryWindow(InventoryWindow);

	CheckLaplasInvStats(InventoryWindow, Laplas);

	PrintInventoryWindow(InventoryWindow);

	return Laplas;
}