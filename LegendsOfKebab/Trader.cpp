#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <conio.h>

#define TRADE_WINDOW_ROWS 30
#define TRADE_WINDOW_COLUMNS 121
#define TRADE_COMMENTS_COUNT 30
#define TRADE_COMMENTS_COLUMNS 270//265
char TradeComments[TRADE_COMMENTS_COUNT][TRADE_COMMENTS_COLUMNS];
int CorretPosition = 0;


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
	CorretPosition = 0;

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
	for (int i = 0; CorretPosition < TRADE_COMMENTS_COLUMNS; CorretPosition++, i++)
	{
		if (Array[type][i] == '\n') break;
		*TradeCommentsPosition[CorretPosition] = Array[type][i];

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

void TradingWithTraderBuy(hero Laplas, cost Cost, char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed, char* TradeCommentsPosition[TRADE_WINDOW_ROWS])
{
	char pressedKey;
	char ans;
	int temp, tempSpel;

	do
	{
		pressedKey = _getch();


		if (pressedKey == 'a' || pressedKey == 'A' || pressedKey == 'ф' || pressedKey == 'Ф')
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
				if (Laplas.MON - Cost.cost1 > 0)
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
		else if (pressedKey == 'b' || pressedKey == 'B' || pressedKey == 'и' || pressedKey == 'И')
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
				if (Laplas.MON - Cost.cost2 > 0) Laplas.MON -= Cost.cost2;
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
		else if (pressedKey == 'c' || pressedKey == 'C' || pressedKey == 'с' || pressedKey == 'С')
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
				if (Laplas.MON - Cost.cost3 > 0) Laplas.MON -= Cost.cost3;
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
		else if (pressedKey == 'd' || pressedKey == 'D' || pressedKey == 'в' || pressedKey == 'В')
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
				if (Laplas.MON - Cost.cost4 > 0)
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
		else if (pressedKey == 'e' || pressedKey == 'E' || pressedKey == 'у' || pressedKey == 'У')
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
				if (Laplas.MON - Cost.cost5 > 0) Laplas.MON -= Cost.cost5;
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

void TradingWithTraderSell(hero Laplas, cost Cost, char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed, char* TradeCommentsPosition[TRADE_WINDOW_ROWS])
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
			PrintTradeWindow(TradeWindow);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON > 0/*товара > 0*/)
				{

					Laplas.MON += Cost.cost2;
					//товар - 1
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
		else if (pressedKey == '2')
		{
			TradeCommentsPrint(TradeCommentsPosition, 19, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 3, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 4, TradeComments);
			PrintTradeWindow(TradeWindow);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON > 0/*товара > 0*/)
				{
					Laplas.MON += Cost.cost3;
					// tovar - 1
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
		else if (pressedKey == '3')
		{
			TradeCommentsPrint(TradeCommentsPosition, 19, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 3, TradeComments);
			TradeCommentsPrint(TradeCommentsPosition, 4, TradeComments);
			PrintTradeWindow(TradeWindow);
			TradeCommentsClear(TradeCommentsPosition);
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON > 0/*tovar > 0*/)
				{
					Laplas.MON += Cost.cost5;
					//tovar - 1
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
		PrintTradeWindow(TradeWindow);
	} while (pressedKey != 27);
}


hero Trade(hero Laplas, int seed)
{
	char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS];
	char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS];

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
			CheckLaplasTradeStats(TradeWindow, Laplas);
			CheckCostStats(TradeWindow, Cost);
			PrintTradeWindow(TradeWindow);
			TradingWithTraderBuy(Laplas, Cost, TradeWindow, seed, TradeCommentsPosition);
			GetTradeMenuWindow(TradeWindow);
			CheckLaplasTradeStats(TradeWindow, Laplas);
			PrintTradeWindow(TradeWindow);
		}
		else if (pressedKey == '2')
		{
			GetTradeSellWindow(TradeWindow);
			GetTradeComments();
			GetTradeCommentsPosition(TradeCommentsPosition, TradeWindow);
			CheckLaplasTradeStats(TradeWindow, Laplas);
			PrintTradeWindow(TradeWindow);
			TradingWithTraderSell(Laplas, Cost, TradeWindow, seed, TradeCommentsPosition);
			GetTradeMenuWindow(TradeWindow);
			CheckLaplasTradeStats(TradeWindow, Laplas);
			PrintTradeWindow(TradeWindow);
		}
		else if (pressedKey == '0')
			exit(1);
	} while (pressedKey != '0');

	return Laplas;
}