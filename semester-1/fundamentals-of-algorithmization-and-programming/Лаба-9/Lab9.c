//Написать функцию, которая инициализирует элементы массива. Функция принимает два аргумента – массив и его размер. В функции ввести с клавиатуры 5 целых чисел и присвоить эти значения элементам массива. Написать функцию определения суммы положительных чисел массива. Функция должна принимать в качестве аргумента массив и возвращать сумму положительных чисел.  В функции main вывести на экран. В случае ошибки вывести 0.
#include <stdlib.h>
#include <stdio.h>
#define col 5
int check(int a) {//ф-ция проверки
    int flag=0;
    printf_s("\nPLease enter element  \n");
    flag = scanf("\n%d", &a);
        while (flag == 0) {
//            system("CLS");
            printf("Error, do not write letters\n");
            rewind(stdin);
            flag = scanf("%d", &a);
        }
        while (a >INT_MAX) {
//            system("CLS");
            if (!flag) {
                printf("Error, do not write letters\n");
            }
            else if (a>INT_MAX) {
                printf("Please enter a number lower tnan int_max \n");
            }
            rewind(stdin);
            flag = scanf("%d", &a);
        }return (a);}
int* Input_Output(int *arr,int a){
for(int i=0;i<col;i++)
    arr[i]=check(arr[i]);
printf("Your array is ");
for(int i=0;i<col;i++)
    printf("%3d",arr[i]);
    return (arr);}

int sum( int* arr){
    int a=0;
    for(int i=0;i<col;i++){
        if(arr[i]>=0)
            a+=arr[i];}
    return (a);
}
int main() {
    int SYMA=0;
    int*mas;
    if(!(mas=calloc(col,sizeof(int)))){//проверка на выделение памяти
        printf("Error");
        return 0;}
mas=Input_Output(mas,col);
SYMA=sum(mas);
printf("\nSum is %d",SYMA);
free(mas);
return 0;}
