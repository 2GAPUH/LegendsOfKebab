#pragma once

struct hero
{
	int HP, MP, DMG, ARM;
};

struct enemy
{
	int HP, DMG, ARM;
};

hero Battle(hero Laplas);
void PrintBattlewindow(char BattleWindow[]);
void GetBattleWindow(char BattleWindow[]);
void CheckLaplasStats(char BattleWindow[], hero Laplas);
void FightWithEnemy(hero Laplas, char BattleWindow[]);
void CheckEnemyStats(char BattleWindow[], enemy unded);