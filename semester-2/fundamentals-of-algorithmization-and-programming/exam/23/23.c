//1) Дан отсортированный текстовый файл. Написать программу добавления русского символа, не нарушая упорядоченности.
#include "stdio.h"
#include "stdlib.h"
#define nameOfile "C:\\Semen\\BSIIR\\OAIP\\sem_2\\exam\\23\\test.txt" // где файл лежит

int isLetter(char letter) { // Clion и кодировки не совместимы,мне лень менять, всё то же самое на кириллице (0_0)
    return ((letter>= 'A' || letter<= 'Z') || (letter>= 'a' || letter<= 'z') )?1:0;
}
int cmpSymbol(char my_letter, char file_letter) { // cделал с игнор кейсом, хз зачем
    if ((my_letter==file_letter || my_letter==file_letter-33) || my_letter==file_letter+31|| my_letter==file_letter+32 || my_letter==file_letter-32 || my_letter==file_letter-1)
        return 1;
        else return 0;
}
FILE* addSymbol(char letter) {
    FILE* file = NULL;
    char file_letter, buffer;
    while(!(file = fopen(nameOfile,"r+"))) {
        puts("This file cannot be open, try again");
        rewind(file);
    }

// finding EOF position
    fpos_t current = 0,end;
    fseek(file,0,2);
    fgetpos(file,&end);
    fseek(file,0,0);

    while(1){
        fgetpos(file,&current);
        if(current == end) {
            if(!cmpSymbol(letter, file_letter)) { // если буква по алфавиту идёт позже то ставится в конец, можно вывести меседж но мне лень и это билет
                fsetpos(file,&current); // опять грёбанная каретка
                fprintf(file, "%c", letter);
            }
            break;
        }
        fscanf(file, "%c",&file_letter);
        if(cmpSymbol(letter, file_letter) && isLetter(letter)) {
            fsetpos(file,&current);
            buffer = file_letter;
            fprintf(file, "%c",letter);
            while(1) {
                fgetpos(file,&current);
                fsetpos(file,&current);
                if(current == end) {
                    fprintf(file, "%c",buffer);
                    break;
                }
                fscanf(file, "%c",&file_letter);
                fsetpos(file,&current);
                buffer = buffer + file_letter;
                file_letter = buffer - file_letter;
                buffer = buffer - file_letter;
                fprintf(file, "%c",file_letter);

            }
            break;
        }
    }
    rewind(file);
    fclose(file);
    return(file);
}
void printFile(FILE* file) {

    while(!(file = fopen(nameOfile,"r"))) {
        puts("This file cannot be open, try again");
        rewind(file);
    }
    char letter = 0;
    // finding EOF position
    fpos_t current = 0,end;
    fseek(file,0,2);
    fgetpos(file,&end);
    fseek(file,0,0);

    while(1) {
        fgetpos(file,&current);
        if(current == end)
            break;
        fscanf(file, "%c",&letter);
        printf("%c", letter);
    }

    fclose(file);

}
int main() {
    FILE* file = NULL ;
    char letter;
    printFile(file);
    printf("\nplease enter a letter");
    rewind(stdin);
    scanf("%c",&letter);
    printFile(addSymbol(letter));
    free(file);
    return 0;
}
