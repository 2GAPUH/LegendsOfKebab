#pragma once
#define BATTLE_WINDOW_ROWS 30
#define BATTLE_WINDOW_COLUMNS 121
#define BATTLE_COMMENTS_COUNT 10
#define BATTLE_COMMENTS_COLUMNS 365

struct hero
{
	int HP, MP, DMG, ARM;
	int MaxHP, MaxMP;
};

struct enemy
{
	int HP, DMG, ARM;
};

void GetBattleWindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS]);
void PrintBattlewindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS]);
void CheckLaplasStats(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], hero Laplas);
void CheckEnemyStats(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], enemy unded);
hero UseHealthPotion(hero Laplas);
void GetBattleComments();
void GetBattleCommentsPosition(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS], char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS]);
void BattleCommentsPrint(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS], int type);
void FightWithEnemy(hero Laplas, enemy Kostyan, char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], int seed, char* BattleCommentsPosition[BATTLE_WINDOW_ROWS]);
hero Battle(hero Laplas, int seed);
void BattleCommentsClear(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS]);