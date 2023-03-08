#pragma once
#define TRADE_WINDOW_ROWS 30
#define TRADE_WINDOW_COLUMNS 121
#define TRADE_COMMENTS_COUNT 10
#define TRADE_COMMENTS_COLUMNS 365

struct cost
{
	int cost1, cost2, cost3, cost4, cost5;
};

hero Trade(hero Laplas, int seed);
void GetTradeMenuWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void GetTradeBuyWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void GetTradeSellWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void PrintTradeWindow(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void CheckLaplasTradeStats(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], hero Laplas);
void CheckCostStats(char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], cost Cost);
void TradingWithTraderBuy(hero Laplas, cost Cost, char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed);
void TradingWithTraderSell(hero Laplas, cost Cost, char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS], int seed);
void GetTradeCommentsPosition(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS], char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void TradeCommentsClear(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS]);
void GetTradeComments();
void GetTradeCommentsPosition(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS], char TradeWindow[TRADE_WINDOW_ROWS][TRADE_WINDOW_COLUMNS]);
void TradeCommentsPrint(char* TradeCommentsPosition[TRADE_COMMENTS_COLUMNS], int type);