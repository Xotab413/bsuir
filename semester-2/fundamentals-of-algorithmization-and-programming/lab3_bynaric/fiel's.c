#include "fiel's.h"
char fileName[]  = "C:\\Semen\\BSIIR\\OAIP\\sem_2\\lab3_bynaric\\";

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
    while (!scanf("\n %d", &num)  || num > INT_MAX) {
        printf("Please enter a number");
        rewind(stdin);
    }

    return num;
}

FILE*
inFile(FILE* file) {
    char* nameFile = fileName;
    int chooseNewNum = 0;
    int num = 0;
    if(!(file = fopen(nameFile,"wb"))) {
        puts("This file cannot be open");
        exit(0);
    }
    do {
        printf("\nenter  number? [1 - yes, other number - no]");
        chooseNewNum = checkNum(chooseNewNum);
        if (chooseNewNum == 1) {
            num = checkNum(num);
            fwrite(&num, sizeof(int), 1, file);
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
    if(!(file = fopen(fileName,"rb"))) {
        puts("This file cannot be open");
        exit(0);
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
        fread(&num, sizeof(int), 1, file);
        printf("%d\n", num);
    }
    fclose(file);
}

void
sort(FILE* file) {
    if(!file) {
        puts("Please enter num in file");
        return;
    }
    int num1 = 0, num2 = 0;
    fpos_t pos1 = 0, pos2 = 0,endPos = 0;

    if (!(file = fopen(fileName, "r+b"))) {
        puts("This file cannot be open");
        exit(0);
    }


    // finding EOF position
    fseek(file,0,2);
    fgetpos(file,&endPos);
    fseek(file,0,0);
    //.............



    while(1) {
        if(pos1 == endPos)
            break;

        fsetpos(file,&pos1);
        fread(&num1, sizeof(int), 1, file);
        pos2 = ftell(file);
        while (1) {
            if(pos2 == endPos)
                break;

            fgetpos(file,&pos2);// remember position of 2 number1
            fsetpos(file,&pos2);

            fread(&num2, sizeof(int), 1, file);

            if(num2 < num1) {
                fsetpos(file,&pos1);
                fwrite(&num2, sizeof(int), 1, file);
                fsetpos(file,&pos2);
                fwrite(&num1, sizeof(int), 1, file);
                num1 = num2;
            }

        }
        pos1+=sizeof(int);
    }
    rewind(file);
    fclose(file);
}

void
revers(FILE* file) {

    if (!(file = fopen(fileName, "r+b"))) {
        puts("This file cannot be open");
        exit(0);
    }

    fpos_t rightPos , end , curPos = 0;
    int num1 = 0, num2 = 0;



    fseek(file,0,2);
    fgetpos(file,&end);
    fseek(file,0,0);



    rightPos = end - sizeof(int);

    while(1) {

        if(rightPos<curPos)
            break;

        fsetpos(file,&curPos);
        fread(&num1, sizeof(int), 1, file);
        fsetpos(file,&rightPos);
        fread(&num2, sizeof(int), 1, file);
        fsetpos(file,&curPos);
        fwrite(&num2, sizeof(int), 1, file);
        fsetpos(file,&rightPos);
        fwrite(&num1, sizeof(int), 1, file);

        fsetpos(file,&curPos);
        curPos += sizeof(int);
        rightPos -= sizeof(int);

    }
    rewind(file);
    fclose(file);

}
void

diffCount(FILE* file) {
    if(!file) {
        puts("Please enter num in file");
        return;
    }
    fpos_t pos1 = 0, pos2 = 0 ,endPos;
    int identicNum = 0, num1 = 0,num2 = 0;


    if (!(file = fopen(fileName, "rb"))) {
        puts("This file cannot be open");
        exit(0);
    }


    // finding EOF position
    fseek(file,0,2);
    fgetpos(file,&endPos);
    fseek(file,0,0);
    //.............





    while(1) {
        if(pos1 == endPos)
            break;

        fsetpos(file,&pos1);
        fread(&num1, sizeof(int), 1, file);
        pos2 = ftell(file);
        while (1) {
            if(pos2 == endPos)
                break;

            fgetpos(file,&pos2);// remember position of 2 number1
            fsetpos(file,&pos2);

            fread(&num2, sizeof(int), 1, file);

            if(num2 == num1)
                identicNum++;
        }
        pos1+=sizeof(int);
    }


    printf("Count of different num = %d", endPos/(sizeof(int)) - identicNum);
    rewind(file);
    fclose(file);

}

void
menu() {
    FILE* file = NULL;
    int chooser = 0;
    do{
        printf("\n Enter: \n");
        printf("1-for entering num in file\n");
        printf("2-for sorting file\n");
        printf("3-for output file\n");
        printf("4-for revers file\n");
        printf("5-for count different num\n");
        printf("other num-for exit\n");
        chooser = checkNum(chooser);
        switch (chooser) {
            case 1:
                puts("Enter fileName");
                enterStr();
                file = inFile(file);
                break;
            case 2:
                sort(file);
                break;
            case 3:
                outFile(file);
                break;
            case 4:
                revers(file);
                break;
            case 5:
                diffCount(file);
                break;
            default: return;
        }
    }while (1);

}
int main() {
    menu();
    return 0;
}