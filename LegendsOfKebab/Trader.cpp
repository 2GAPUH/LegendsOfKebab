#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include "Inventory.h"

#define TRADE_WINDOW_ROWS 30
#define TRADE_WINDOW_COLUMNS 121
#define TRADE_COMMENTS_COUNT 30
#define TRADE_COMMENTS_COLUMNS 270
#define DESC_WINDOW 234
#define OBJ_WINDOW 165
#define OBJ_HEIGHT 5
#define OBJ_WIDTH 15
#define DESC_HEIGHT 6
#define DESC_WIDTH 40
#define COST_WINDOW_ROWS 5
#define COST_WINDOW_COLUMNS 3

char TradeComments[TRADE_COMMENTS_COUNT][TRADE_COMMENTS_COLUMNS];
char descriptionTr[DESC_HEIGHT][DESC_WIDTH];
char objectsTr[OBJ_HEIGHT][OBJ_WIDTH];
int CorPosition = 0;
int CorPosition0Tr = 0;
int CorPosition1Tr = 0;



struct cost
{
	int cost1, cost2, cost3, cost4, cost5;
};


void TradeInventoryClear(char* array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*array[i] = 32;

	}
	CorPosition1Tr = 0;
	CorPosition0Tr = 0;
}


void TradeGetObjectPosition(char* ar_position[OBJ_WINDOW], char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS])
{
	int n = 24, j = 19;
	for (int i = 0; i < OBJ_WINDOW; i++, j++)
	{
		if (j == 33)
		{
			n++;
			j = 19;
		}
		ar_position[i] = &(TradeWindow[n][j]);
	}
}

void TradeGetDescriptionPosition(char* ar_position[DESC_WINDOW], char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS])
{
	int n = 24, j = 66;
	for (int i = 0; i < DESC_WINDOW; i++, j++)
	{
		if (j == 118)
		{
			n++;
			j = 66;
		}
		ar_position[i] = &(TradeWindow[n][j]);
	}

}


void TradeGetObjects()
{
	FILE* f;
	if (fopen_s(&f, "ItemsTr.txt", "rt") == 0)
	{
		for (int i = 0; i < OBJ_HEIGHT; i++)
			for (int j = 0; j < OBJ_WIDTH; j++)
				fscanf_s(f, "%c", &objectsTr[i][j]);
		fclose(f);
	}
	else
	{
		printf("Can't load the level!");
		exit(1);
	}
}

void TradeGetDescription()
{
	FILE* f;
	if (fopen_s(&f, "DescriptionItems.txt", "rt") == 0)
	{
		for (int i = 0; i < DESC_HEIGHT; i++)
			for (int j = 0; j < DESC_WIDTH; j++)
				fscanf_s(f, "%c", &descriptionTr[i][j], 1);
		fclose(f);
	}
	else
	{
		printf("Can't load the level!");
		exit(1);
	}
}


void TradeInventoryObjectPrint(char* ar_position[OBJ_WINDOW], int type)
{
	for (int i = 0; CorPosition0Tr < OBJ_WINDOW; CorPosition0Tr++, i++)
	{
		if (objectsTr[type][i] == '\n') break;
		*ar_position[CorPosition0Tr] = objectsTr[type][i];

	}
}

void TradeInventoryDescriptionPrint(char* ar_position[DESC_WINDOW], int type)
{
	for (int i = 0; CorPosition1Tr < DESC_WINDOW; CorPosition1Tr++, i++)
	{
		if (descriptionTr[type][i] == '\n') break;
		*ar_position[CorPosition1Tr] = descriptionTr[type][i];

	}
}

void GetTradeComments()
{
	FILE* file;
	char temp;

	fopen_s(&file, "TradeComments.txt", "r");

	for (int i = 0; i < TRADE_COMMENTS_COUNT; i++)
		for (int n = 0; n < TRADE_COMMENTS_COLUMNS; n++)
		{
			fscanf_s(file, "%c", &temp);
			TradeComments[i][n] = temp;
			if (temp == '\n') break;

		}

	fclose(file);
}

void TradeCommentsClear(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS])
{
	for (int i = 0; i < TRADE_COMMENTS_COLUMNS; i++)
	{
		*TradeCommentsPosition[i] = 32;

	}
	CorPosition = 0;

}


void GetTradeCommentsPosition(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS], char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS])
{
	int n = 23, j = 65;
	for (int i = 0; i < TRADE_COMMENTS_COLUMNS; i++, j++)
	{
		if (j == 118)
		{
			n++;
			j = 65;
		}
		TradeCommentsPosition[i] = &(TradeWindow[n][j]);
	}

}


void TradeCommentsPrint(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS], int type, char Array[TRADE_COMMENTS_COUNT][TRADE_COMMENTS_COLUMNS])
{
	for (int i = 0; CorPosition < TRADE_COMMENTS_COLUMNS; CorPosition++, i++)
	{
		if (Array[type][i] == '\n') break;
		*TradeCommentsPosition[CorPosition] = Array[type][i];

	}
}

void GetTradeMenuWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS])
{
	FILE* f;

	fopen_s(&f, "Trader_Menu.txt", "r");

	for (int i = 0; i < TRADE_WINDOW_ROWS; i++)
		for (int n = 0; n < TRADE_WINDOW_COLUMNS; n++)
			fscanf_s(f, "%c", &TradeWindow[i][n]);

	fclose(f);
}

void GetTradeBuyWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS])
{
	FILE* f;

	fopen_s(&f, "Trader_Buy.txt", "r");

	for (int i = 0; i < TRADE_WINDOW_ROWS; i++)
		for (int n = 0; n < TRADE_WINDOW_COLUMNS; n++)
			fscanf_s(f, "%c", &TradeWindow[i][n]);

	fclose(f);
}

void GetTradeSellWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS])
{
	FILE* f;

	fopen_s(&f, "Trader_Sell.txt", "r");

	for (int i = 0; i < TRADE_WINDOW_ROWS; i++)
		for (int n = 0; n < TRADE_WINDOW_COLUMNS; n++)
			fscanf_s(f, "%c", &TradeWindow[i][n]);

	fclose(f);
}

void PrintTradeWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS])
{
	system("cls");
	for (int i = 0; i < TRADE_WINDOW_ROWS; i++)
		for (int n = 0; n < TRADE_WINDOW_COLUMNS; n++)
			printf_s("%c", TradeWindow[i][n]);
	
}

void CheckLaplasTradeStats(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], hero Laplas)
{
	TradeWindow[24][6] = Laplas.DMG / 100 + 48;
	TradeWindow[24][7] = Laplas.DMG / 10 % 10 + 48;
	TradeWindow[24][8] = Laplas.DMG % 10 + 48;

	TradeWindow[25][5] = Laplas.HP / 100 + 48;
	TradeWindow[25][6] = Laplas.HP / 10 % 10 + 48;
	TradeWindow[25][7] = Laplas.HP % 10 + 48;

	TradeWindow[26][5] = Laplas.MP / 100 + 48;
	TradeWindow[26][6] = Laplas.MP / 10 % 10 + 48;
	TradeWindow[26][7] = Laplas.MP % 10 + 48;

	TradeWindow[27][6] = Laplas.ARM / 100 + 48;
	TradeWindow[27][7] = Laplas.ARM / 10 % 10 + 48;
	TradeWindow[27][8] = Laplas.ARM % 10 + 48;

	TradeWindow[28][6] = Laplas.MON / 1000 + 48;
	TradeWindow[28][7] = Laplas.MON / 100 % 10 + 48;
	TradeWindow[28][8] = Laplas.MON / 10 % 10 + 48;
	TradeWindow[28][9] = Laplas.MON % 10 + 48;
}

void CheckCostStats(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], cost Cost)
{
	TradeWindow[23][58] = Cost.cost1 / 100 + 48;
	TradeWindow[23][59] = Cost.cost1 / 10 % 10 + 48;
	TradeWindow[23][60] = Cost.cost1 % 10 + 48;

	TradeWindow[24][58] = Cost.cost2 / 100 + 48;
	TradeWindow[24][59] = Cost.cost2 / 10 % 10 + 48;
	TradeWindow[24][60] = Cost.cost2 % 10 + 48;

	TradeWindow[25][58] = Cost.cost3 / 100 + 48;
	TradeWindow[25][59] = Cost.cost3 / 10 % 10 + 48;
	TradeWindow[25][60] = Cost.cost3 % 10 + 48;

	TradeWindow[26][58] = Cost.cost4 / 100 + 48;
	TradeWindow[26][59] = Cost.cost4 / 10 % 10 + 48;
	TradeWindow[26][60] = Cost.cost4 % 10 + 48;

	TradeWindow[27][58] = Cost.cost5 / 100 + 48;
	TradeWindow[27][59] = Cost.cost5 / 10 % 10 + 48;
	TradeWindow[27][60] = Cost.cost5 % 10 + 48;
}

void CheckCostStatsSell(char TradeWindowSell[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], cost Cost)
{
	TradeWindowSell[24][49] = Cost.cost2 / 100 + 48;
	TradeWindowSell[24][50] = Cost.cost2 / 10 % 10 + 48;
	TradeWindowSell[24][51] = Cost.cost2 % 10 + 48;

	TradeWindowSell[25][49] = Cost.cost3 / 100 + 48;
	TradeWindowSell[25][50] = Cost.cost3 / 10 % 10 + 48;
	TradeWindowSell[25][51] = Cost.cost3 % 10 + 48;

	TradeWindowSell[26][49] = Cost.cost5 / 100 + 48;
	TradeWindowSell[26][50] = Cost.cost5 / 10 % 10 + 48;
	TradeWindowSell[26][51] = Cost.cost5 % 10 + 48;

}

void TradeCheckCountObjects(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], hero Laplas)
{
	TradeWindow[24][34] = Laplas.Invent[0] / 10 % 10 + 48;
	TradeWindow[24][35] = Laplas.Invent[0] % 10 + 48;

	TradeWindow[25][34] = Laplas.Invent[1] / 10 % 10 + 48;
	TradeWindow[25][35] = Laplas.Invent[1] % 10 + 48;

	TradeWindow[26][34] = Laplas.Invent[2] / 10 % 10 + 48;
	TradeWindow[26][35] = Laplas.Invent[2] % 10 + 48;

	TradeWindow[27][35] = Laplas.Invent[3] % 10 + 48;

	TradeWindow[28][34] = Laplas.Invent[4] / 10 % 10 + 48;
	TradeWindow[28][35] = Laplas.Invent[4] % 10 + 48;
}

void TradingWithTraderBuy(hero &Laplas, cost Cost, char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed, char* TradeCommentsPosition[TRADE_WINDOW_ROWS])
{
	char pressedKey;
	char ans;
	int temp, tempSpel;

	do
	{
		pressedKey = _getch();


		if (pressedKey == 'a' || pressedKey == 'A' || pressedKey == 'ô' || pressedKey == 'Ô')
		{
			TradeCommentsPrint(TradeCommentsPosition, 1, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 2, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 3, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 4, TradeComments);
			PrintTradeWindow(TradeWindow);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON - Cost.cost1 > 0 && Laplas.DMG < 90)
				{
					Laplas.MON -= Cost.cost1;
					Laplas.DMG += 30;
				}
				else
				{
					TradeCommentsPrint(TradeCommentsPosition, 5, TradeComments);
					PrintTradeWindow(TradeWindow);
					TradeCommentsClear(TradeCommentsPosition);
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == 'b' || pressedKey == 'B' || pressedKey == 'è' || pressedKey == 'È')
		{
			TradeCommentsPrint(TradeCommentsPosition, 7, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 8, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 3, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 4, TradeComments);
			PrintTradeWindow(TradeWindow);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON - Cost.cost2 > 0 && Laplas.Invent[0] < 99)
				{
					Laplas.MON -= Cost.cost2;
					Laplas.Invent[0] += 1;
					TradeCheckCountObjects(TradeWindow, Laplas);
				}
				else
				{
					TradeCommentsPrint(TradeCommentsPosition, 5, TradeComments);
					PrintTradeWindow(TradeWindow);
					TradeCommentsClear(TradeCommentsPosition);
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == 'c' || pressedKey == 'C' || pressedKey == 'ñ' || pressedKey == 'Ñ')
		{
			TradeCommentsPrint(TradeCommentsPosition, 10, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 11, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 3, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 4, TradeComments);
			PrintTradeWindow(TradeWindow);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON - Cost.cost3 > 0)
				{
					Laplas.MON -= Cost.cost3;
					Laplas.Invent[1] += 1;
					TradeCheckCountObjects(TradeWindow, Laplas);
				}
				else
				{
					TradeCommentsPrint(TradeCommentsPosition, 5, TradeComments);
					PrintTradeWindow(TradeWindow);
					TradeCommentsClear(TradeCommentsPosition);
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == 'd' || pressedKey == 'D' || pressedKey == 'â' || pressedKey == 'Â')
		{
			TradeCommentsPrint(TradeCommentsPosition, 13, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 14, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 3, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 4, TradeComments);
			PrintTradeWindow(TradeWindow);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON - Cost.cost4 > 0 && Laplas.ARM < 75)
				{
					Laplas.MON -= Cost.cost4;
					Laplas.ARM += 15;
				}
				else
				{
					TradeCommentsPrint(TradeCommentsPosition, 5, TradeComments);
					PrintTradeWindow(TradeWindow);
					TradeCommentsClear(TradeCommentsPosition);
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == 'e' || pressedKey == 'E' || pressedKey == 'ó' || pressedKey == 'Ó')
		{
			TradeCommentsPrint(TradeCommentsPosition, 16, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 17, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 3, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 4, TradeComments);
			PrintTradeWindow(TradeWindow);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON - Cost.cost5 > 0 && Laplas.Invent[2] < 99)
				{
					Laplas.MON -= Cost.cost5;
					Laplas.Invent[2] += 1;
					TradeCheckCountObjects(TradeWindow, Laplas);
				}
				else
				{
					TradeCommentsPrint(TradeCommentsPosition, 5, TradeComments);
					PrintTradeWindow(TradeWindow);
					TradeCommentsClear(TradeCommentsPosition);
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else continue;
		CheckLaplasTradeStats(TradeWindow, Laplas);
		CheckCostStats(TradeWindow, Cost);
		PrintTradeWindow(TradeWindow);
		TradeCommentsClear(TradeCommentsPosition);
	} while (pressedKey != 27);
}



void TradingWithTraderSell(hero &Laplas, cost Cost, char TradeWindowSell[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed, char* TradeCommentsPosition[TRADE_WINDOW_ROWS])
{
	char pressedKey;
	char ans;

	do
	{
		pressedKey = _getch();


		if (pressedKey == '1')
		{
			TradeCommentsPrint(TradeCommentsPosition, 18, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 3, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 4, TradeComments);
			PrintTradeWindow(TradeWindowSell);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.Invent[0] > 0)
				{
					Laplas.MON += Cost.cost2;
					Laplas.Invent[0] -= 1;
					TradeCheckCountObjects(TradeWindowSell, Laplas);
				}
				else
				{
					TradeCommentsPrint(TradeCommentsPosition, 21, TradeComments);
					PrintTradeWindow(TradeWindowSell);
					TradeCommentsClear(TradeCommentsPosition);
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == '2')
		{
			TradeCommentsPrint(TradeCommentsPosition, 19, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 3, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 4, TradeComments);
			PrintTradeWindow(TradeWindowSell);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.Invent[1] > 0)
				{
					Laplas.MON += Cost.cost3;
					Laplas.Invent[1] -= 1;
					TradeCheckCountObjects(TradeWindowSell, Laplas);
				}
				else
				{
					TradeCommentsPrint(TradeCommentsPosition, 21, TradeComments);
					PrintTradeWindow(TradeWindowSell);
					TradeCommentsClear(TradeCommentsPosition);
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == '3')
		{
			TradeCommentsPrint(TradeCommentsPosition, 19, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 3, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 4, TradeComments);
			PrintTradeWindow(TradeWindowSell);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.Invent[2] > 0)
				{
					Laplas.MON += Cost.cost5;
					Laplas.Invent[2] -= 1;
					TradeCheckCountObjects(TradeWindowSell, Laplas);
				}
				else
				{
					TradeCommentsPrint(TradeCommentsPosition, 21, TradeComments);
					PrintTradeWindow(TradeWindowSell);
					TradeCommentsClear(TradeCommentsPosition);
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == '4')
		{
			TradeCommentsPrint(TradeCommentsPosition, 22, TradeComments);
			PrintTradeWindow(TradeWindowSell);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != 13);
		}
		else continue;
		CheckLaplasTradeStats(TradeWindowSell, Laplas);
		PrintTradeWindow(TradeWindowSell);
	} while (pressedKey != 27);
}



hero Trade(hero &Laplas, int seed)
{
	system("chcp 866");
	char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS];
	char TradeWindowSell[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS];
	char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS];
	char* object_position[OBJ_WINDOW];
	char* description_position[DESC_WINDOW];

	cost Cost = { 600, 50, 50, 500, 150 };

	GetTradeMenuWindow(TradeWindow);
	CheckLaplasTradeStats(TradeWindow, Laplas);
	PrintTradeWindow(TradeWindow);

	char pressedKey;
	char ans;
	do
	{
		pressedKey = _getch();
		if (pressedKey == '1')
		{
			GetTradeBuyWindow(TradeWindow);
			GetTradeComments();
			GetTradeCommentsPosition(TradeCommentsPosition, TradeWindow);
			TradeGetObjectPosition(object_position, TradeWindow);
			TradeGetDescriptionPosition(description_position, TradeWindow);
			TradeGetObjects();
			TradeGetDescription();
			CheckLaplasTradeStats(TradeWindow, Laplas);
			CheckCostStats(TradeWindow, Cost);
			TradeCheckCountObjects(TradeWindow, Laplas);
			for (int i = 0; i < 5; i++)
				TradeInventoryObjectPrint(object_position, i);
			PrintTradeWindow(TradeWindow);
			TradingWithTraderBuy(Laplas, Cost, TradeWindow, seed, TradeCommentsPosition);
			GetTradeMenuWindow(TradeWindow);
			CheckLaplasTradeStats(TradeWindow, Laplas);
			PrintTradeWindow(TradeWindow);
			TradeInventoryClear(description_position, DESC_WINDOW);
		}
		else if (pressedKey == '2')
		{
			GetTradeSellWindow(TradeWindowSell);
			GetTradeComments();
			GetTradeCommentsPosition(TradeCommentsPosition, TradeWindowSell);
			TradeGetObjectPosition(object_position, TradeWindowSell);
			TradeGetDescriptionPosition(description_position, TradeWindowSell);
			TradeGetObjects();
			TradeGetDescription();
			CheckLaplasTradeStats(TradeWindowSell, Laplas);
			CheckCostStatsSell(TradeWindowSell, Cost);
			TradeCheckCountObjects(TradeWindowSell, Laplas);
			for (int i = 0; i < 5; i++)
				TradeInventoryObjectPrint(object_position, i);
			PrintTradeWindow(TradeWindowSell);
			TradingWithTraderSell(Laplas, Cost, TradeWindowSell, seed, TradeCommentsPosition);
			GetTradeMenuWindow(TradeWindowSell);
			CheckLaplasTradeStats(TradeWindowSell, Laplas);
			PrintTradeWindow(TradeWindowSell);
			TradeInventoryClear(description_position, DESC_WINDOW);
		}
		else if (pressedKey == '0')
			return Laplas;
	} while (pressedKey != '0');


	system("chcp 1251");
	return Laplas;
}