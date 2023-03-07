#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include "Battle.h"
#include "StartMenu.h"
#include "Trader.h"
#include "Inventory.h"

int main()
{
	system("chcp 866");
	system("color F0");
	system("cls");
	system("mode con cols=122  lines=31");
	int seed, a;
	srand(seed = time(NULL));

	hero Laplas = { 200, 65, 30, 20, 760, 250, 100, 0, 0 };

	StartMenu();

	do {
		system("cls");
		printf("Trade(1) or Inv(2) or Battle(3)?"); scanf("%d", &a);
	} while (a != 1 && a != 2 && a != 3);

	if (a == 1)
		Laplas = Trade(Laplas, seed);
	else if (a == 2)
		Laplas = Inventory(Laplas, seed);
	else if (a == 3)
		Laplas = Battle(Laplas, seed);



	return 0;
}