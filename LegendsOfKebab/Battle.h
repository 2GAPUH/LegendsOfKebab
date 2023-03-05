#pragma once
#define BATTLE_WINDOW_ROWS 30
#define BATTLE_WINDOW_COLUMNS 121


struct hero
{
	int HP, MP, DMG, ARM;
};

struct enemy
{
	int HP, DMG, ARM;
};

hero Battle(hero Laplas, int seed);
void PrintBattlewindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS]);
void GetBattleWindow(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS]);
void CheckLaplasStats(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], hero Laplas);
void FightWithEnemy(hero Laplas, char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], int seed);
void CheckEnemyStats(char BattleWindow[BATTLE_WINDOW_ROWS][BATTLE_WINDOW_COLUMNS], enemy unded);
