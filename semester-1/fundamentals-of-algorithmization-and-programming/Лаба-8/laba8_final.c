
//7. Дан текст. Выделить все слова в предложениях, состоящих только из цифр. Определить сумму чисел во всех предложениях.
#define _CRT_SECURE_NO_WARNINGS//убирает предупреждение)
#include<stdio.h>
#include <stdlib.h>
void inout(char**,int,int);
int ato1_sum( char**,int,int);
void offset(char**,int,int);
void output(char**,int,int);
int abc(int);
void free_arr(char**,int);
void check(int);
int k=0;
int main() {
    char **mas;
    int sum;
    int number_of_rows,number_of_columns;
    printf("\nplease enter a count of rows\n");
    scanf("%d", &number_of_rows);
    check(number_of_rows);
   printf("\nplease enter a count of symbols");
    scanf("%d", &number_of_columns);
    check(number_of_columns);

    mas = (char **) calloc(number_of_rows, sizeof(char *));
 if(!mas)
 {
    puts("Errror");
    return 228;
 }
    for (int i = 0; i < number_of_rows; i++)
    {
        mas[i] = ((char *) calloc(number_of_columns+3, sizeof(char)));
        if(!mas[i])
        {
            puts("Errror");
            return 228;
        }
    }

    inout(mas,number_of_rows,number_of_columns);
    sum=ato1_sum( mas, number_of_rows, number_of_columns);
    putchar('\n');
    printf("\n sum is %d",sum);
    offset(mas,number_of_rows,k);
    printf_s("\nText2:");
    output(mas,number_of_rows,number_of_columns);
    free_arr(mas,number_of_rows);
    return 0;
}
void inout(char**mas,int n,int a){
    printf("\n Enter a string no more like %d and symbols not more %d\n", n, a);
    printf_s("\nEnter your text:\n");
    for (int i = 0; i<n; i++)
    {  rewind(stdin);
        fgets(mas[i], a+1, stdin);

    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < a+2; j++)
            if(mas[i][j]!=0)
                k++;//подсчет символо(если меньше ввел чем задумано)

printf("%d",k);
    printf_s("\nText:");

    for (int i = 0; i < n; i++){
        putchar('\n');
        for (int j = 0; j < a+1; j++)
            printf_s("%c", *(*(mas+i)+j));}

}//ввод вывод исходного текста
int ato1_sum(char **mas,int n,int a){
    int znak=1,sum=0,o=0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < a+2; j++)
        {
            if(mas[i][j]=='-')
            {
                znak=-1;
            }
            if(mas[i][j] == '+' ||mas[i][j] == '-') // пропуск знака в строке
                j++;
            if(mas[i][j]==' '||mas[i][j]=='\n'||mas[i][j]=='\0')
            {   znak=1;//сброс счетчика
                o*=znak;
                sum+=o;
                o=0;
            }
            if(mas[i][j] >= '0' && mas[i][j] <= '9')
            {
                o=znak*(10 * abc(o) + (mas[i][j] - '0'));
            }

        }
        sum+=o;
    }
    return(sum);
}//находит числа и их сумму
void offset(char**mas,int n,int a){
    for (int i = 0; i < n; i++)
        for (int j=a+1; j>0 ; j--)
            mas[i][j]=mas[i][j-1];

    for (int i = 0; i < n; i++){
        mas[i][a+2]=' ';
        mas[i][0] = ' ';}
    int symbols=0,digit=0;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < a+2; j++) {
            symbols++;

//            printf("\nsymbols=%d",symbols);
            if (mas[i][j] >= '0' && mas[i][j] <= '9'||mas[i][j]=='-')
                digit++;
            if (mas[i][j]==' '&&symbols>1) {
                symbols--;
                if (digit == symbols) {
//                    printf("digit=%d",digit);
                    system("color 2");
                    mas[i][j] = '!';
                    mas[i][j-1-symbols]='!';
                    symbols = 0;
                    digit = 0;
                } else {
                    symbols = 0;
                    digit = 0;
                }
            }
        }
}//сдвиг+выделение
void output(char**mas,int n,int a){
    for (int i = 0; i < n; i++){
        putchar('\n');
        for (int j = 0; j < a+4; j++){
            printf_s("%c", *(*(mas+i)+j));
    }
}
}//вывод текста
int abc(int d){
if(d<0)
    d*=-1;
else d*=1;
    return (d);
}//аналог abs
void free_arr(char**mas,int n){
    for (int j = 0; j < n; j++)
        free(mas[j]);
    free(mas);
}//освобождениеее!!!
void check(int n) {
    int flag=0;
    do {//блок проверки
        flag = scanf("%d", &n);
        if (!flag) {
//            system("CLS");//use in visual studio
            printf("Error,please enter a number\n");
            rewind(stdin);//чистим чистим
        }

        if (flag!=0 && n < 0 ) {
//            system("CLS");//use in visual studio
            printf("Please enter a positive number :) \n");
            rewind(stdin);
        }
    } while ( flag == 0 || n < 0);
}

