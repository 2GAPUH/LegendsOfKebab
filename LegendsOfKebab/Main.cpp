#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include "Battle.h"
#include "StartMenu.h"


int main()
{
	system("chcp 866");
	system("color F0");
	system("cls");
	system("mode con cols=122  lines=31");
	int seed;
	srand(seed = time(NULL));

	hero Laplas = {234, 61, 27, 3, 250, 100};

	StartMenu();

	Laplas = Battle(Laplas, seed);



	return 0;
}