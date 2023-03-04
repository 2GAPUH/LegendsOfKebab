#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int doNumber_1()
{


	return 0;
}




int main()
{
	//system("chcp 1251");

	int numberOfExercise;

	do
	{
		printf("Enter exercise number: "); scanf("%d", &numberOfExercise);
		switch (numberOfExercise)
		{
		case 1:doNumber_1(); break;


		case 0:printf("Program finished."); break;
		default:printf("Invalid exercise number!\n");
		}
	} while (numberOfExercise != 0);


	return 0;
}