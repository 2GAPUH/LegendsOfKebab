#pragma once
#define INVENTORY_WINDOW_ROWS 30
#define INVENTORY_WINDOW_COLUMNS 121

heroTr Inventory(heroTr Laplas, int seed);
void GetInventoryWindow(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS]);
void PrintInventoryWindow(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS]);
void CheckLaplasInvStats(char InventoryWindow[INVENTORY_WINDOW_ROWS][INVENTORY_WINDOW_COLUMNS], hero Laplas);
