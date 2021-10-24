//Даны натуральное число n, символы s1,...,sn. Преобразовать последовательность s1,...,sn, удалив каждый символ * и повторив каждый символ, отличный от *.
//без доп массива
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enter();
void double_char();
void gen();

int n = 0;
int col;
char* mas_of_char;

int main() {
    int a = 0;
    system("color 2");

    while (1) {//chooser like in 6 lab
        printf("Enter 1 for hand write, 2 for random generating\n");
        scanf("%d", &a);
        rewind(stdin);
        if (a == 1) {
//          puts("Please enter a count of symbols");
            printf("Please enter a count of symbols");
            scanf("%d", &n);
            mas_of_char = calloc(n * 2+3, sizeof(char));
            enter();
            break;
        }
        if (a == 2) {
//          puts("Please enter a count of symbols");
            printf("Please enter a count of symbols\n");
            scanf("%d", &n);
            mas_of_char = calloc(n * 2+3, sizeof(char));
            gen();
            break;
        }
        //system("CLS");
        printf("Error try again\n");
    }
     double_char(n);
    for (int i = 0; i < n*2+2; i++) {//output
        printf("%c", mas_of_char[i]);
    }
    //puts(mas_of_char);
    free(mas_of_char);//Free pointer
    return 0;
}
void enter() {//Just simple enter by hand
    for(int i=0;i<2*n+2;i+=2) {
        mas_of_char[i] = (char) getchar();
        printf("%c", mas_of_char[i]);
    }
    //puts(mas_of_char);//output  current string
}
void gen(){
    srand(time(NULL));
    for (int i = 0; i <2*n+2; i+=2) {
        mas_of_char[i] = ('!' + rand() % ('z' - 'a'));//Random symbols
        printf("%c", mas_of_char[i]);
    }
    printf("\n");
    //puts(mas_of_char);
}
void double_char() {
    int j=0;

    for(int i=1;i<2*n+2;i+=2){
        if(mas_of_char[j]!='*'){
            j+=2;
            mas_of_char[i]=mas_of_char[i-1];}
        else { for (int k=j;k<2*n+2;k+=2)
            mas_of_char[k]=mas_of_char[k+2];
        i+=-2;}
    }

}