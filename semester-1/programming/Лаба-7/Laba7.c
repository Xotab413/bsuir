//Даны натуральное число n, символы s1,...,sn. Преобразовать последовательность s1,...,sn, удалив каждый символ * и повторив каждый символ, отличный от *.
#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enter();
char* double_char();
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
            mas_of_char = calloc(n * 2, sizeof(char));
            enter();
            break;
        }
        if (a == 2) {
//          puts("Please enter a count of symbols");
            printf("Please enter a count of symbols\n");
            scanf("%d", &n);
            mas_of_char = calloc(n * 2, sizeof(char));
            gen();
            break;
        }
        //system("CLS");
        printf("Error try again\n");
    }
    mas_of_char = double_char(n);
    for (int i = 0; i < ((n - col) * 2); i++) {//output
        printf("%c", mas_of_char[i]);
    }
    //puts(mas_of_char);
    free(mas_of_char);//Free pointer
    return 0;
}
void enter() {//Just simple enter by hand
    for(int i=0;i<n;i++) {
        mas_of_char[i] = (char) getchar();
        printf("%c", mas_of_char[i]);
    }
    //puts(mas_of_char);//output  current string
}
void gen(){
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        mas_of_char[i] = ('!' + rand() % ('z' - 'a'));//Random symbols
        printf("%c", mas_of_char[i]);
    }
    printf("\n");
    //puts(mas_of_char);
}
char* double_char() {
    col = 0;//count of '*' symbols
    char* mas;//we use "another" array for duplicate current

    for (int j = 0; j < n; j++) if (mas_of_char[j] == '*') col++;

    mas = (char *) calloc(((n - col) * 2), sizeof(int));//allocating memory for an array
    int j = 0;//index of current array
    for (int i = 0; i < n; i++) {
        if (mas_of_char[i] != '*') {
            mas[j] = mas_of_char[i];
            mas[j + 1] = mas_of_char[i];
            j += 2;//bcs 2 symbols))
        }
    }
    return mas;
}
