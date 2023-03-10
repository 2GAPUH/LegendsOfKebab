#pragma once
#define INVENTORY_WINDOW_ROWS 29
#define INVENTORY_WINDOW_COLUMNS 120
#define INVENTORY_COMMENTS_COLUMNS 270
#define DESC_WINDOW 234
#define OBJ_WINDOW 65
#define OBJ_HEIGHT 6
#define OBJ_WIDTH 27
#define DESC_HEIGHT 6
#define DESC_WIDTH 40

hero Inventory(hero Laplas, int seed);
void GetObjectPosition(char* ar_position[OBJ_WINDOW], char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS]);
void GetDescriptionPosition(char* ar_position[DESC_WINDOW], char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS]);
void GetInventoryWindow(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS]);
void GetObjects();
void GetDescription();
void InventoryObjectPrint(char* ar_position[OBJ_WINDOW], int type);
void InventoryDescriptionPrint(char* ar_position[DESC_WINDOW], int type);
void PrintInventoryWindow(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS]);
void CheckLaplasInvStats(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS], hero Laplas);
void MovingInventory(char* choice_obj[], char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS], char* description_position[DESC_WINDOW]);
void InventoryClear(char* array[]);
void CheckCountObjects(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS], hero Laplas);
