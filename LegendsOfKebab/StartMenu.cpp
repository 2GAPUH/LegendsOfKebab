#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define START_MENU_WINDOW_ROWS 30
#define START_MENU_WINDOW_COLUMNS 121




void PrintStartMenuWindow(char StartMenuWindow[START_MENU_WINDOW_ROWS][START_MENU_WINDOW_COLUMNS])
{
	system("cls");
	for (int i = 0; i < START_MENU_WINDOW_ROWS;i++)
		for (int n = 0; n < START_MENU_WINDOW_COLUMNS; n++)
			printf_s("%c", StartMenuWindow[i][n]);

}


void GetStartMenuWindow(char StartMenuWindow[START_MENU_WINDOW_ROWS][START_MENU_WINDOW_COLUMNS])
{
	FILE* f;

	fopen_s(&f, "StartMenu.txt", "r");

	for (int i = 0; i < START_MENU_WINDOW_ROWS;i++)
		for (int n = 0; n < START_MENU_WINDOW_COLUMNS; n++)
			fscanf_s(f, "%c", &StartMenuWindow[i][n]);

	fclose(f);
}


void StartMenu()
{
	PlaySound(L"main_menu_full.wav", NULL, SND_LOOP | SND_ASYNC);
	char StartMenuWindow[START_MENU_WINDOW_ROWS][START_MENU_WINDOW_COLUMNS];

	GetStartMenuWindow(StartMenuWindow);

	PrintStartMenuWindow(StartMenuWindow);

	_getch();
}