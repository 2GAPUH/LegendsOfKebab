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
#include "Map.h"


int main()
{
	system("chcp 866");
	system("color F0");
	system("cls");
	system("mode con cols=122  lines=31");
	int seed, a;
	srand(seed = time(NULL));

	hero Laplas = {234, 61, 27, 3, 250, 100, 0, 0};
	heroTr LaplasTr = { 200, 65, 30, 50, 760 };
	cost Cost = { 500, 500, 50, 50, 150 };

	StartMenu();

	do {
		system("cls");
		printf("Trade(1) or Inv(2) or Battle(3) or Map(4)?"); scanf("%d", &a);
	} while (a != 1 && a != 2 && a != 3 && a != 4);

	if (a == 1)
		LaplasTr = Trade(LaplasTr, seed);
	else if (a == 2)
		LaplasTr = Inventory(LaplasTr, seed);
	else if (a ==3)
		Laplas = Battle(Laplas, seed);
	else if (a == 4)
		map();



	return 0;
}