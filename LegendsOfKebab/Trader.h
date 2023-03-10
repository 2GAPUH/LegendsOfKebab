#pragma once
#define TRADE_WINDOW_ROWS 30
#define TRADE_WINDOW_COLUMNS 121
#define TRADE_COMMENTS_COUNT 10
#define TRADE_COMMENTS_COLUMNS 365
#define DESC_WINDOW 234
#define OBJ_WINDOW 156
#define OBJ_HEIGHT 6
#define OBJ_WIDTH 27
#define DESC_HEIGHT 6
#define DESC_WIDTH 40
#include "Inventory.h"

struct cost
{
	int cost1, cost2, cost3, cost4, cost5;
};

hero Trade(hero &Laplas, int seed);
void GetTradeMenuWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void GetTradeBuyWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void GetTradeSellWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void PrintTradeWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void CheckLaplasTradeStats(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], hero Laplas);
void CheckCostStats(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], cost Cost);
void TradingWithTraderBuy(hero &Laplas, cost Cost, char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed);
void TradingWithTraderSell(hero &Laplas, cost Cost, char TradeWindowSell[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed);
void GetTradeCommentsPosition(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS], char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void TradeCommentsClear(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS]);
void GetTradeComments();
void GetTradeCommentsPosition(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS], char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void TradeCommentsPrint(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS], int type);
void TradeInventoryClear(char* array[], int n);
void TradeGetObjectPosition(char* ar_position[OBJ_WINDOW], char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void TradeGetDescriptionPosition(char* ar_position[DESC_WINDOW], char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void TradeGetObjects();
void TradeGetDescription();
void TradeInventoryObjectPrint(char* ar_position[OBJ_WINDOW], int type);
void TradeInventoryDescriptionPrint(char* ar_position[DESC_WINDOW], int type);
void CheckCostStatsSell(char TradeWindowSell[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], cost Cost);
void TradeCheckCountObjects(char InventoryWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], hero Laplas);