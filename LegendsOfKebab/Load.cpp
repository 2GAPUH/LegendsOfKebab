#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Inventory.h"


hero load(hero &Laplas, int &x, int &y, int &currentLocation)
{
	FILE* f;

	fopen_s(&f, "saves.txt", "r");

	fscanf_s(f, "%d", &Laplas.HP);
	fscanf_s(f, "%d", &Laplas.MP);
	fscanf_s(f, "%d", &Laplas.DMG);
	fscanf_s(f, "%d", &Laplas.ARM);
	fscanf_s(f, "%d", &Laplas.MON);
	fscanf_s(f, "%d", &Laplas.HP);
	fscanf_s(f, "%d", &Laplas.MaxHP);
	fscanf_s(f, "%d", &Laplas.MaxMP);
	fscanf_s(f, "%d", &Laplas.Resist);
	fscanf_s(f, "%d", &Laplas.Crit);
	fscanf_s(f, "%d", &Laplas.Invent[0]);
	fscanf_s(f, "%d", &Laplas.Invent[1]);
	fscanf_s(f, "%d", &Laplas.Invent[2]);
	fscanf_s(f, "%d", &Laplas.Invent[3]);
	fscanf_s(f, "%d", &Laplas.Invent[4]);
	fscanf_s(f, "%d", &Laplas.Invent[5]);
	fscanf_s(f, "%d", &x);
	fscanf_s(f, "%d", &y);
	fscanf_s(f, "%d", &currentLocation);

	fclose(f);

	return Laplas;
}