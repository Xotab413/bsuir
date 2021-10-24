//Лаба 3 задние 5))
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void check();//функция проверки
void num_count();//функция подсчёта
int n, k = 0, flag = 0;
int main() {
	printf_s("Enter a nubmer <= 99: ");
	check();
	num_count();
	return(0);
}
void check() {
	do {//блок проверки 
		flag = scanf_s("%d", &n);
		if (n > 99) {
			system("CLS");
			printf("Please enter a number lower tnan 100\n");
			rewind(stdin);
		}
		if (!flag) {
			system("CLS");
			printf("Error,please enter a number\n");
			rewind(stdin);//чистим чистим
		}
		
		if (flag!=0 && n < 0 ) {
			system("CLS");
			printf("Please enter a positive number :) \n");
			rewind(stdin);
		}
	} while (n > 99 || flag == 0 || n < 0);
}
void num_count() {
	printf_s("k20,k10,k5,k1\n");
	for (int k20 = 0; k20 <= (n / 20); k20++)//идем от большего к меньшему 
		for (int k10 = 0; k10 <= (n - k20 * 20) / 10; k10++)
			for (int k5 = 0; k5 <= (n - k20 * 20 - k10 * 10) / 5; k5++)
			{
				int k1 = (n - k20 * 20 - k10 * 10 - k5 * 5);
				printf_s("%d %d %d %d\n", k20, k10, k5, k1); k++;
			}
	printf_s("Value of ways: %d", k);//выводим кол-во случаев
}
