// 15 Определить, является ли данный квадратный массив симметричным относительно своей главной диагонали.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void gen(int**);
int** create_random();
int** create_user(int);
void choose();
void print();
int check(int, int);
void count();
void compare();
int** mas, i, n, j, cor = 0, col = 0;
int* arr1 , *arr2;

int main() {
    choose();
    puts("\n Your matrix:");
    print();
    count();
    compare();
    for (i = 0; i < n; i++)
        free(mas[i]);
    free(mas);
    return (0);
}
int** create_user() {//ф-ция создание  матрицы(вручную)
    mas = calloc(n, sizeof(int*));
    for (i = 0; i < n; i++) {
        mas[i] = (int*)calloc(n, sizeof(int));
        for (j = 0; j < n; j++)
            check(mas[i][j], 2);
    }
    return (mas);
}
int** create_random() {//ф-ция создание рандомной матрицы
    int** mak ;
    mak = calloc(n, sizeof(int*));
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        mak[i] = (int*)calloc(n, sizeof(int));
        //printf_s("%d",(mas+i));
        for (j = 0; j < n; j++)
            mak[i][j] = rand() % 10;
    }
    return (mak);
}
int check(int a, int b) {//ф-ция проверки
    int flag;
    if (b == 1) {
        do {
            flag = scanf("%d", &a);
            if (a > 4) {
//                system("CLS");
                printf("Please enter a number lower tnan 4\n");
                rewind(stdin);
            }
            if (!flag) {
//                system("CLS");
                printf("Error,please enter a number\n");
                rewind(stdin);//чистим
            }

            if (flag != 0 && a < 0) {
//                system("CLS");
                printf("Please enter a positive number :) \n");
                rewind(stdin);
            }
        } while (a > 4 || flag == 0 || a < 0);
        return(a);
    }
    else if(b == 0) {
        puts("PLease enter a number of rows&columns");
        do {
            flag = scanf("%d", &n);
            if (!flag) {
//                system("ClS");
                printf("Error,please enter a number\n");
                rewind(stdin);
            }

            if (n < 0 && flag != 0) {
//                system("CLS");
                printf("Please enter a positive number :) \n");
                rewind(stdin);
            }
        } while (flag == 0 || n < 0);
        return(n);
    }
    if (b == 2) {
        printf_s("PLease enter elements ");
        flag = scanf("%d", &mas[i][j]);
        while (mas[i][j] < 0) {
//            system("CLS");
            if (!flag) {
                printf("Error, do not write letters\n");
            }
            else if (mas[i][j] < 0) {
                printf("Please enter a positive number :) \n");
            }
            rewind(stdin);
            flag = scanf("%d", &mas[i][j]);
        }
        while (flag == 0) {
//            system("CLS");
            printf("Error, do not write letters\n");
            rewind(stdin);
            flag = scanf("%d", &mas[i][j]);
        }
        while (mas[i][j] > INT_MAX || mas[i][j] < 0) {

//            system("CLS");
            if (!flag) {
                printf("Error, do not write letters\n");
            }
            else if (mas[i][j] > INT_MAX) {
                printf("Please enter a number lower tnan int_max \n");
            }
            else if (mas[i][j] < 0) {
                printf("Please enter a positive number :) \n");
            }
            rewind(stdin);
            flag = scanf("%d", &mas[i][j]);
        }
    }
    return (mas[i][j]);
}
void print() {//ф-ция вывода матрицы
    for (i = 0; i < n; i++) {
        printf_s("\n ");
        for (j = 0; j < n; j++)
            printf_s("%4d ", mas[i][j]);
    }
    puts("\n");
}
void gen(int **mak) {//ф-ция генерации симметричной матрицы
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            mak[j][i] = mak[i][j];
    }
}
void count() {
    int k = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) cor++;
    } //count cisel nad diagonal

    arr1 = calloc(cor, sizeof(int));
    arr2 = calloc(cor, sizeof(int));
    puts("\n");
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            k++;
            arr1[k] = mas[i][j];
            /* printf_s("%4d", *(arr1 + k));*/
        }
    }
    puts("\n");
    k = 0;
    for (j = 0; j < n - 1; j++) {
        for (i = j + 1; i < n; i++) {
            k++;
            arr2[k] = mas[i][j];
            /*   printf_s("%4d", *(arr2 + k));*/
        }
    }
}
void compare() {//проверка на симметричность
    for (int k = 1; k < cor + 1; k++) {
        if (arr1[k] == arr2[k]) {
            col++;
            printf_s("\n  equal elements %d", *(arr1+k));
        }
    }
    puts("\n");
    if (col == cor && cor != 0) printf_s("\n Your matrix is symmetric");
    else if (cor == 0) puts("\nThis is not matrix it is a NUMBER -_-");
    else puts("\n Your matrix is not symmetric");
}
void choose() {
    int d = 0;
    puts("Hello this is first functional program please choose a variant of program 1,2,3 ");
    puts("\n 1-is typical input by keyboard 2-is random input and 3-is a random generation of symmetric matrix");//i added 3  (to confirm that my program is working properly)
    switch (check(d, 1)) {
        case 1:
            check(n, 0);
            mas = create_user(n);
            break;
        case 2:
            check(n, 0);
            mas = create_random();
            break;
        case 3:
            check(n, 0);
            mas = create_random();
            gen(mas);
            break;
    }
}
