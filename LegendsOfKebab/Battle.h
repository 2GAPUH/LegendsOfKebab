#pragma once
#include "Inventory.h"
#define BATTLE_WINDOW_ROWS 30
#define BATTLE_WINDOW_COLUMNS 121
#define BATTLE_COMMENTS_COUNT 30
#define BATTLE_COMMENTS_COLUMNS 365


struct enemy
{
	int HP, DMG, ARM;
	int Stun, Burning;
};

void GetBattleWindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], int mob);
void PrintBattleWindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS]);
void CheckLaplasStats(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], hero Laplas);
void CheckEnemyStats(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], enemy unded);
void GetBattleComments();
void GetBattleCommentsPosition(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS], char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS]);
void BattleCommentsPrint(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS], int type, char Array[BATTLE_COMMENTS_COUNT][BATTLE_COMMENTS_COUNT]);
hero FightWithEnemy(hero Laplas, enemy Kostyan, char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], int seed, char* BattleCommentsPosition[BATTLE_WINDOW_ROWS], char* ChoiceMagic[], int mob);
hero Battle(hero Laplas, int seed, int mob);
void BattleCommentsClear(char* BattleCommentsPosition[BATTLE_COMMENTS_COLUMNS]);
int FightCalculation(hero* Laplas, enemy* Kostyan, char pressedKey);