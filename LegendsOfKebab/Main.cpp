#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include "StartMenu.h"
#include "FirstLoc.h"
#include "Inventory.h"
#include "KebabLoc.h"
#include <conio.h>
#include "Load.h"
#include "Source.h"

int main()
{
	system("chcp 866");
	system("color F0");
	system("cls");
	system("mode con cols=122  lines=31");
	int seed, a;
	srand(seed = time(NULL));
	char pressedKey;

	hero Laplas = { 200, 65, 30, 5, 760, 250, 100, 0, 0 , 1, 10, 20, 1, 0,0};
	int x, y, currentLocation;


	StartMenu();

	do {
		pressedKey = _getch();

		if (pressedKey == 13)
		{
			FirstLoc(10, 25, Laplas);
		}
		else if (pressedKey == 32)
		{
			load(Laplas, x, y, currentLocation);
			goNextLocation(10, currentLocation, x, y, Laplas);
		}

	} while (pressedKey != 27);




	/*
	do {
		system("cls");
		printf("Trade(1) or Inv(2) or Battle(3) or Map(4)?"); scanf("%d", &a);
	} while (a != 1 && a != 2 && a != 3 && a != 4);

	if (a == 1)
		Laplas = Trade(Laplas, seed);
	else if (a == 2)
		Laplas = Inventory(Laplas, seed);
	else if (a == 3)
		Laplas = Battle(Laplas, seed);
	else if (a == 4)
		map();*/



	return 0;
}