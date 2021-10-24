//15-я задача Матусевич Семён
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
//Инициализация
 long int a, b, y;//объявляем переменные а б у and e.t.c
 int flag, count = 0;
 long float x;// объявляем переменную х
 long  int z=1000000000; //объявление переменной z и присваивание ей макс. значения
 void check();//функция проверки
 void num_count();//функция подсчёта цифр
int main()
{   check();
	num_count();
	return(0);
}

void check(){
	printf_s("Reshenie yravninia vida: y=ax+b\n");
	printf_s("vvedite y,a,b\n");
do//цикл закончится когда будет введено число!!
{
	flag = scanf_s("%ld%ld%ld", &y, &a, &b);//вводим переменные у а б и присваиваем их значение переменной flag
	if (flag == 0)
	{
		system("CLS");//очистка экрана 
		printf("Error,please enter a number\n");
		rewind(stdin);// чистка буфера ввода
	}
	if (y>=z || b >=z) {
		system("CLS");
		printf_s("Please enter a value less than = %ld\n", z);
	}
} while (flag == 0 || y >=z || b >=z);//пока error равна 0 или превышение значения переменных
do //цикл закончится когда будут введены переменные y и b не равные между собой(при этом а не равно нулю)
	{
	if (y == b && a != 0)
	{
		printf_s("Beskonechno mnogo resheniy\n");
		rewind(stdin);
		exit(0);//Возвращение  в ОС
	}
} while (y == b && a != 0);
}
void num_count(){
		if (a != 0) {//если а не равно нулю то цикл выполняется
			b = y - b;
			x = (long float)b / a;
			printf_s("%.1lf", x);
			while (x > 1) {
				x /= 10;
				count++;
			}// Подсчёт кол-ва цифр
			if (count < 10) {
				for (int i = 0; i < 10 - count; i++)
				{
					printf(" %c", '*');
				}
				
			}
		}
		else { printf_s("NEt resheniy"); }
	}
