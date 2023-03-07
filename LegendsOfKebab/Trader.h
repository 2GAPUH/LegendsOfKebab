#pragma once
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

heroTr Trade(heroTr Laplas, int seed);
void PrintTradeWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void GetTradeWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void CheckLaplasTradeStats(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], heroTr Laplas);
void CheckCostStats(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], cost Cost);
void TradingWithTrader(heroTr Laplas, cost Cost, char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed);