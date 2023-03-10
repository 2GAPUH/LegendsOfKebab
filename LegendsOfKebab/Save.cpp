#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Inventory.h"


void save(hero &Laplas, int x, int y, int currentLocation)
{
	FILE* f;

	fopen_s(&f, "saves.txt", "w");

	fprintf_s(f, "%d ", Laplas.HP);
	fprintf_s(f, "%d ", Laplas.MP);
	fprintf_s(f, "%d ", Laplas.DMG);
	fprintf_s(f, "%d ", Laplas.ARM);
	fprintf_s(f, "%d ", Laplas.MON);
	fprintf_s(f, "%d ", Laplas.HP);
	fprintf_s(f, "%d ", Laplas.MaxHP);
	fprintf_s(f, "%d ", Laplas.MaxMP);
	fprintf_s(f, "%d ", Laplas.Resist);
	fprintf_s(f, "%d ", Laplas.Crit);
	fprintf_s(f, "%d ", Laplas.Invent[0]);
	fprintf_s(f, "%d ", Laplas.Invent[1]);
	fprintf_s(f, "%d ", Laplas.Invent[2]);
	fprintf_s(f, "%d ", Laplas.Invent[3]);
	fprintf_s(f, "%d ", Laplas.Invent[4]);
	fprintf_s(f, "%d ", Laplas.Invent[5]);
	fprintf_s(f, "%d ", x);
	fprintf_s(f, "%d ", y);
	fprintf_s(f, "%d ", currentLocation);

	fclose(f);

}