#include "text_file.h"
char fileName[]  = "C:\\Semen\\BSIIR\\OAIP\\sem_2\\lab3_text\\";
void
enterStr() {
    char* str;
    int i = 0;
    str = (char *) malloc((i + 1) * sizeof(char));
    rewind(stdin);
    scanf("%c", &str[i]);
    i++;
    while (1) {
        str = (char *) realloc(str, sizeof(char) * (i + 1));
        scanf("%c", &str[i]);

        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
    strcat(fileName, str);
}
int
checkNum(int num) {
    while (!scanf("\n %d", &num)  || num > 999) {
        printf("Please try again :) ");
        rewind(stdin);
    }

    return num;
}

FILE*
inFile(FILE* file) {
    char* nameFile = fileName;
    int chooseNewNum = 0;
    int num = 0;
    while(!(file = fopen(nameFile,"w"))) {
        puts("This file cannot be open, try again");
        rewind(file);
    }
    do {
        printf("\nenter  number? [1 - yes, other number - no]");
        chooseNewNum = checkNum(chooseNewNum);
        if (chooseNewNum == 1) {
            num = checkNum(num);
            fprintf(file, "%4d",num);
        } else {
            rewind(file);
            break;
        }
    } while(1);

    fclose(file);
    return file;
}

void
outFile(FILE* file) {
    if(!file) {
        puts("Please enter num in file");
        return;
    }
    int num = 0 ;
    while(!(file = fopen(fileName,"r"))) {
        puts("This file cannot be open, try again");
        rewind(file);
    }

    // finding EOF position

    fpos_t l1 = 0,l2;
    fseek(file,0,2);
    fgetpos(file,&l2);
    fseek(file,0,0);

    //
    while(!feof(file)) {
        fgetpos(file,&l1);
        if(l2 == l1)
            break;
        fscanf(file, "%4d",&num);
        printf("%4d\n", num);
    }
    fclose(file);
}

void
even(FILE* file) {
    if(!file) {
        puts("Please enter num in file");
        return;
    }
    int num = 0 ;
    if(!(file = fopen(fileName,"r"))) {
        puts("This file cannot be open, try again");
        return;
    }


    // finding EOF position

    fpos_t l1 = 0,l2;
    fseek(file,0,2);
    fgetpos(file,&l2);
    fseek(file,0,0);

    //
    while(!feof(file)) {
        fgetpos(file,&l1);
        if(l2 == l1)
            break;
        fscanf(file, "%4d",&num);
        if(!(num%2))
        printf("%4d\n", num);
    }
    fclose(file);
}

void
multply(FILE* file) {
    FILE* file2 = NULL;
    int num1 = 0, num2 = 0;
    char fileName2[] = "C:\\Semen\\BSIIR\\OAIP\\sem_2\\lab3_text\\multiply.txt";

    if(!file) {
        puts("Please enter num in file");
        return;
    }

    if(!(file2 = fopen(fileName2,"w+"))) {
        puts("This file cannot be open, try again");
        rewind(file2);
    }
    if(!(file = fopen(fileName,"r"))) {
        puts("This file cannot be open, try again");
        rewind(file);
    }

        fscanf(file, "%4d",&num1);
        fscanf(file, "%4d",&num2);




    int multuplNum = num1 * num2;
    int int21 = num2 / 100;
    int int22 = (num2 / 10)%10;
    int int23 = num2 % 10;
    fprintf(file2,"                %4d\n", num1);
    fputs("               x\n",file2);
    fprintf(file2,"                %4d\n", num2);
    fputs("            --------\n",file2);
    fprintf(file2,"               %4d\n", int23 * num2);
    if (int21 * num1 == 0 && int22 * num1 == 0);
    else {
        fprintf(file2,"          +   %4d\n", int22 * num1);
        if (int21 * num1 == 0);
        else fprintf(file2,"             %4d\n", int21 * num1);
        fputs("            --------\n",file2);
        fprintf(file2, "             %8d\n", multuplNum);
    }
}
void

menu() {
    FILE* file = NULL;
    int chooser = 0;
    do{
        printf("\n Enter: \n");
        printf("1-for entering num in file\n");
        printf("2-for finding even num\n");
        printf("3-for output file\n");
        printf("4-for multiply num's file\n");
        printf("other num-for exit\n");
        chooser = checkNum(chooser);
        switch (chooser) {
            case 1:
                puts("Enter fileName");
                enterStr();
                file = inFile(file);
                break;
            case 2:
                even(file);
                break;
            case 3:
                outFile(file);
                break;
            case 4:
                multply(file);
                break;
            default: return;
        }
    }while (1);

}

int main() {
    menu();
    return 0;
}