#include <iostream>
#include <time.h>
#include <conio.h>
#include<windows.h>
#include<stdlib.h>
#include "Inventory.h"
void kosti(int x)
{
	switch (x)
	{
	case 1:
		printf_s("--------------- \n");
		printf_s("|             | \n");
		printf_s("|             | \n");
		printf_s("|      0      | \n");
		printf_s("|             | \n");
		printf_s("|             | \n");
		printf_s("--------------- \n");
		break;
	case 2:
		printf_s("--------------- \n");
		printf_s("|             | \n");
		printf_s("|             | \n");
		printf_s("| 0         0 | \n");
		printf_s("|             | \n");
		printf_s("|             | \n");
		printf_s("--------------- \n");
		break;
	case 3:
		printf_s("--------------- \n");
		printf_s("| 0           | \n");
		printf_s("|             | \n");
		printf_s("|      0      | \n");
		printf_s("|             | \n");
		printf_s("|           0 | \n");
		printf_s("--------------- \n");
		break;
	case 4:
		printf_s("--------------- \n");
		printf_s("| 0         0 | \n");
		printf_s("|             | \n");
		printf_s("|             | \n");
		printf_s("|             | \n");
		printf_s("| 0         0 | \n");
		printf_s("--------------- \n");
		break;
	case 5:
		printf_s("--------------- \n");
		printf_s("| 0         0 | \n");
		printf_s("|             | \n");
		printf_s("|      0      | \n");
		printf_s("|             | \n");
		printf_s("| 0         0 | \n");
		printf_s("--------------- \n");
		break;
	case 6:
		printf_s("--------------- \n");
		printf_s("| 0         0 | \n");
		printf_s("|             | \n");
		printf_s("| 0         0 | \n");
		printf_s("|             | \n");
		printf_s("| 0         0 | \n");
		printf_s("--------------- \n");
		break;
	}
}

int Dice(hero &Laplas)
{

	setlocale(LC_ALL, "ru");
	system("cls");
	srand(time(NULL));
	int Igrok, Bot, i, bet;
	printf_s("Ваш баланс:%d \n", Laplas.MON);
	printf_s("Правила игры просты - нужно просто набрать больше очков чем твой противник. \n");
	do { 
		printf_s("Выбирите действие \n 1 -> Сделать ставку \n 2 -->  бросить кости \n 3 -- > узнать результат \n 4 -> выйти из игры \n");
		scanf_s("%d", &i);
		switch (i) {
		case 1:
			system("cls");
			printf_s("Введите сумму ставки --> ");
			do {
				scanf_s("%d", &bet);
				if (bet > Laplas.MON || bet < 0)
					printf_s("Ваша ставка некорректна ");
			} while (bet > Laplas.MON || bet <= 0);
			break;
		case 2:
			system("cls");
			Igrok = rand() % 6 + 1;
			kosti(Igrok);
			Bot = rand() % 6 + 1;
			kosti(Bot);
			break;
		case 3:
			system("cls");
			if (Igrok > Bot) {
				Laplas.MON += bet;
				printf_s("Вы победили , держите свой выигрышь \n Ваш балланс --> %d ", Laplas.MON);
			}
			if (Bot > Igrok) {
				Laplas.MON -= bet;
				printf_s(" Вы проиграли \n Ваш балланс --> %d ", Laplas.MON);
			}
			if (Bot == Igrok) {
				printf_s("Ничья");
				printf_s(" Ваш балланс --> %d \n", Laplas.MON);
			}break;
		}
	} while (i != 4);

	return 0;

}

