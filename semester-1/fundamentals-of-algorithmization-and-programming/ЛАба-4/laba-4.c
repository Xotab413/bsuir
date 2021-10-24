//laba 4
// if we use keyboard, uncomment ))
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define SIZE 10
#define MIN 5
void check();//function of check's(if it needed)
void count();
void k_enter();
//void r_enter();
int mas[SIZE];
int min = INT_MAX, cor = 0;
int main() {
	printf_s("Count of minimum's: 5\n");
	check();
	/*r_enter();*/
	count();
	return (0);
}
void check() {
	printf_s("Please enter a 10 number's\n");
	int flag = 0;//IF we enter through keyboard, not random))//блок проверки
	for (int i = 0; i < SIZE; i++) {
		flag = scanf_s("%d", &mas[i]);
		while (mas[i] < 0) {
			system("CLS");
			if (!flag) {
				printf("Error, do not write letters\n");
			}
			else if (mas[i] < 0) {
				printf("Please enter a positive number :) \n");
			}
			rewind(stdin);
			flag = scanf_s("%d", &mas[i]);
		}
		while (flag == 0) {
			system("CLS");
			printf("Error, do not write letters\n");
			rewind(stdin);//чистим чистим
			flag = scanf_s("%d", &mas[i]);
		}
		while (mas[i] > 11|| mas[i] < 0) {
				
					system("CLS");
					if (!flag) {
						printf("Error, do not write letters\n");
					}
					else if (mas[i] > 11) {
						printf("Please enter a number lower tnan 11\n");
					}
					else if (mas[i] < 0) {
						printf("Please enter a positive number :) \n");
					}
					rewind(stdin);
					flag = scanf_s("%d", &mas[i]);
				}
		
	}
}
//void r_enter() {//ф-ция радномного ввода
//	srand(time(NULL));
//	for (int i = 0; i < SIZE; i++) {
//		mas[i] = rand() % 10;
//		printf_s("%d ", mas[i]);
//	}
//}
void count() {
	printf_s("\n");
	for (int i = 0; i < MIN; i++) {//только 5 минимумов 
		for (int j = 0; j < SIZE; j++) {
			if (mas[j] < min) {
				min = mas[j];
				cor = j;//запоминаем индекс эл-та
			}
		}
	mas[cor] = INT_MAX;//вместо мин эл-та в массиве ставим на его место "чучело"(чтобы его пропускать)
	min = INT_MAX;}
	for (int i = 0; i < SIZE; i++) {
		if (mas[i] != INT_MAX) {//выборка выводного потока
			printf("%d ", mas[i]);
		}
	}
}
