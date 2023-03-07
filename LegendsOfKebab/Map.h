#pragma once
#define WINDOW_HEIGHT 30
#define WINDOW_WIDTH 122

#define FIRST_LOCATION 0
#define HOUSE 1

#define HEAL_POTION 1
#define DAMAGE_POTION 2
#define MANA_POTION 3
#define ARMOR_POTION 4
#define KEBAB 5

#define NPC_FL 1 
#define ENEMY_FL 1

#define ENEMY 0
#define NPC 1

struct HeroMap
{
	int x;
	int y;

};





struct Enemy
{
	int x;
	int y;
};

struct Npc
{
	int x;
	int y;
};

struct AnLocCord 
{
	int x;
	int y;
};

int map();
void heroMovement(HeroMap* hero, char map[WINDOW_HEIGHT][WINDOW_WIDTH]);
void heroColision(HeroMap hero, Enemy enemyes[ENEMY_FL], Npc npcs[NPC_FL]);
void GetMapFromFile(const char* filename, char map[WINDOW_HEIGHT][WINDOW_WIDTH]);
void PrintMap(HeroMap hero, char map[WINDOW_HEIGHT][WINDOW_WIDTH], Enemy enemyes[ENEMY_FL], Npc npcs[NPC_FL]);
