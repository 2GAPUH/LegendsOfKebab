#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include "Battle.h"


int main()
{
	system("color F0");
	system("cls");

	hero Laplas = {234, 61, 27, 3};



	Laplas = Battle(Laplas);



	return 0;
}