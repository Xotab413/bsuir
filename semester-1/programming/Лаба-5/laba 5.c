//laba 5 number 2 
//Дана действительная квадратная матрица порядка n. Найти наибольшее из значений элементов, расположенных в заштрихованной части матрицы
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void count();
void check();
int i, j, mas[100][100], max = INT_MIN, por=0,cor=0,N;
int main() {
	printf_s("Enter N..\n");
	check();
	count();
}
void check() {
	int flag = 0;
	do {//блок проверки 
		flag = scanf_s("%d", &N);
		if (N > 100) {
			system("CLS");
			printf("Please enter a number lower tnan 100\n");
			rewind(stdin);
		}
		if (!flag) {
			system("CLS");
			printf("Error,please enter a number\n");
			rewind(stdin);//чистим чистим
		}

		if (flag != 0 && N < 0) {
			system("CLS");
			printf("Please enter a positive number :) \n");
			rewind(stdin);
		}
	} while (N > 99 || flag == 0 || N < 0);
}
void count() {
	srand(time(NULL));
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			mas[i][j] = rand() % 100;
	printf_s("Your current matrix");
	for (i = 0; i < N; i++) {
		printf_s("\n");
		for (j = 0; j < N; j++) {
			printf_s("%d ", mas[i][j]);
		}
	}
	printf_s("\nSecond Matrix:");
	if (N < 3)
		printf_s("NOPE))");
	for (i = 0; i < N / 2; i++) {
		printf_s("\n");
		for (j = 1 + i; j < N - i - 1; j++) {
			printf_s("%d ", mas[i][j]);
		}
	}
	for (i = 0; i < N / 2; i++) {
		for (j = 1 + i; j < N - i - 1; j++)
			if (mas[i][j] > max) {
				max = mas[i][j];
				cor = i;
				por = j;
			}

	}
	if (max == INT_MIN){
		printf_s("This matrix dont iclude this type of figure)");
		exit(0);
}
	printf("\nmaximum element = %d \nhis index is [%d][%d] ", max, cor, por);
}
