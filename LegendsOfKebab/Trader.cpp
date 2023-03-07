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

struct heroTr
{
	int HP, MP, DMG, ARM, MON;
};

struct cost
{
	int cost1, cost2, cost3, cost4, cost5;
};

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

void CheckLaplasTradeStats(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], heroTr Laplas)
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

void TradingWithTraderBuy(heroTr Laplas, cost Cost, char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed)
{
	char pressedKey;
	char ans;

	do
	{
		pressedKey = _getch();


		if (pressedKey == 'a' || pressedKey == 'A' || pressedKey == '�' || pressedKey == '�')
		{
			system("cls");
			printf("Upgrade Sword - Gives you 30 DMG");
			printf("\nDo you want to Upgrade Sword?");
			printf("\n1 - Yes");
			printf("\n0 - No");
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
					printf("\nYou don't have enought money! Press Enter");
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == 'b' || pressedKey == 'B' || pressedKey == '�' || pressedKey == '�')
		{
			system("cls");
			printf("Health Potion - Restores 50 HP");
			printf("\nDo you want to buy a Health Potion?");
			printf("\n1 - Yes");
			printf("\n0 - No");
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON - Cost.cost2 > 0) Laplas.MON -= Cost.cost2;
				else
				{
					printf("\nYou don't have enought money! Press Enter");
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == 'c' || pressedKey == 'C' || pressedKey == '�' || pressedKey == '�')
		{
			system("cls");
			printf("Mana Potion - Restores 50 MP");
			printf("\nDo you want to buy a Mana Potion?");
			printf("\n1 - Yes");
			printf("\n0 - No");
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON - Cost.cost3 > 0) Laplas.MON -= Cost.cost3;
				else
				{
					printf("\nYou don't have enought money! Press Enter");
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == 'd' || pressedKey == 'D' || pressedKey == '�' || pressedKey == '�')
		{
			system("cls");
			printf("Upgrade Armor - Gives you 15 ARM");
			printf("\nDo you want to Upgrade Armor?");
			printf("\n1 - Yes");
			printf("\n0 - No");
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
					printf("\nYou don't have enought money! Press Enter");
					do {
						ans = _getch();
					} while (ans != 13);
				}
			}
			else
				ans = '0';
		}
		else if (pressedKey == 'e' || pressedKey == 'E' || pressedKey == '�' || pressedKey == '�')
		{
			system("cls");
			printf("Kebab - Restores 75 HP and 75 MP");
			printf("\nDo you want to buy a Kebab?");
			printf("\n1 - Yes");
			printf("\n0 - No");
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON - Cost.cost5 > 0) Laplas.MON -= Cost.cost5;
				else
				{
					printf("\nYou don't have enought money! Press Enter");
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
	} while (pressedKey != 27);
}

void TradingWithTraderSell(heroTr Laplas, cost Cost, char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed)
{
	char pressedKey;
	char ans;

	do
	{
		pressedKey = _getch();


		if (pressedKey == '1')
		{
			system("cls");
			printf("\nDo you want to sell your Health Potion?");
			printf("\n1 - Yes");
			printf("\n0 - No");
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON > 0/*������ > 0*/)
				{

					Laplas.MON += Cost.cost2;
					//����� - 1
				}
				else
				{
					printf("\nYou don't have enought Health Potion! Press Enter");
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
			system("cls");
			printf("\nDo you want to sell your Mana Potion?");
			printf("\n1 - Yes");
			printf("\n0 - No");
			do {
				ans = _getch();
			} while (ans != '1' && ans != '0');
			if (ans == '1')
			{
				if (Laplas.MON > 0/*������ > 0*/)
				{
					Laplas.MON += Cost.cost3;
					// tovar - 1
				}
				else
				{
					printf("\nYou don't have enought Mana Potion! Press Enter");
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
			system("cls");
			printf("\nDo you want to sell your Kebab?");
			printf("\n1 - Yes");
			printf("\n0 - No");
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
					printf("\nYou don't have enought Kebab! Press Enter");
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


heroTr Trade(heroTr Laplas, int seed)
{
	char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS];

	cost Cost = { 500, 50, 50, 500, 150 };

	GetTradeMenuWindow(TradeWindow);
	PrintTradeWindow(TradeWindow);

	char pressedKey;
	char ans;
	do
	{
		pressedKey = _getch();
		if (pressedKey == '1')
		{
			GetTradeBuyWindow(TradeWindow);
			PrintTradeWindow(TradeWindow);
			TradingWithTraderBuy(Laplas, Cost, TradeWindow, seed);
			GetTradeMenuWindow(TradeWindow);
			PrintTradeWindow(TradeWindow);
		}
		else if (pressedKey == '2')
		{
			GetTradeSellWindow(TradeWindow);
			PrintTradeWindow(TradeWindow);
			TradingWithTraderSell(Laplas, Cost, TradeWindow, seed);
			GetTradeMenuWindow(TradeWindow);
			PrintTradeWindow(TradeWindow);
		}
		else if (pressedKey == '0')
			exit(1);
	} while (pressedKey != '0');

	return Laplas;
}