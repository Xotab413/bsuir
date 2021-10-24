#include "queue.h"

#pragma region Basic function
void
enterSurname(client *str) {
    int i = 0;
    str->surname = (char *) malloc((i + 1) * sizeof(char));
    scanf("%c", &str->surname[i]);
    while (1) {
        str->surname = (char *) realloc(str->surname, sizeof(char) * (i + 1));
        scanf("%c", &str->surname[i]);
        if (str->surname[i] == '\n') {
            str->surname[i] = '\0';
            break;
        }
        i++;
    }
}
void
enterAccNum(client *str) {
    int i = 0;
    str->nor.account_num = (char *) malloc((i + 1) * sizeof(char));
    scanf("%c", &str->nor.account_num[i]);
    while (1) {
        str->nor.account_num = (char *) realloc(str->nor.account_num, sizeof(char) * (i + 1));
        scanf("%c", &str->nor.account_num[i]);
        if (str->nor.account_num[i] == '\n') {
            str->nor.account_num[i] = '\0';
            break;
        }
        i++;
    }
}
char *
enterStr(char *str) {
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
    return str;
}
int
strCmp(const char* s1,const char* s2) {
    while (*s2 && *s1 && (*s1 == *s2 || *s1 == *s2 - 32 || *s1 == *s2 + 32)) ++s1, ++s2;
    return (*s1 > *s2 ? 1 : (*s1 < *s2 ? -1 : 0));
}
int
checkNum(int  num) {
    while (!scanf("%d", &num) || num < 0 || num > INT_MAX) {
        printf("Please enter a number");
        rewind(stdin);
    }
    return num;
}
void
checkDeposSum(client *client_arr) {
    while (!scanf("%f", &(client_arr)->nor.depos_amount)) {
        printf("Please enter a number");
        scanf("%f", &(client_arr)->nor.depos_amount);
        rewind(stdin);
    }
}
void
checkPass(client *client_arr) {
    while (!scanf("%d", &(client_arr)->pas_num)) {
        printf("Please enter a number");
        scanf("%d", &(client_arr)->pas_num);
        rewind(stdin);
    }
}
void
printCritter(client *c) {
    if(c->flag)
        printf("\nSurname: %s\t Passport number : %d\t Account number or Deposit sum : %f \n",  c->surname, c->pas_num, c->nor.depos_amount);
    else
        printf("\nSurname: %s\t Passport number : %d\t Account number or Deposit sum : %s \n",  c->surname, c->pas_num, c->nor.account_num);
}
void
printBar() {
    printf("\n\n\n |Num||Surname||  Passport||   Account number   || Deposit sum|\n");
}
#pragma endregion

#pragma region Queue function
void
EnterStructure(client** clientListHead, client** clientListTail) {
    int chooser = 0;
    client *pDatabase = NULL;
    do
    {
        if(!(pDatabase = (client*)calloc(1, sizeof(client)))) {
            puts("Not enought memory");
            return;
        }
        puts("Enter surname of client");
        enterSurname(pDatabase);
        puts("Enter passport number");
        checkPass(pDatabase);
        puts("Enter 1 - for entering deposit sum, 2 - for entering account num");

        do {
            chooser = checkNum(chooser);

            if(chooser == 1) {
                (pDatabase)->flag = 1;
                puts("Enter a deposit sum");
                checkDeposSum(pDatabase);
                break;
            }
            if(chooser == 2)  {
                (pDatabase)->flag = 0;
                puts("Enter Account num");
                enterAccNum(pDatabase);
                break;
            }
            else {
                puts("Try again");
            }
        }while (1);


        if (!*clientListHead) {
            *clientListTail = *clientListHead = pDatabase;
        }
        else {
            (*clientListTail)->next = pDatabase;
            (*clientListTail) = pDatabase;
        }
        puts("One more? (y/n)");
        fflush(stdin);
    } while (getchar() == 'y');
}
void
ShowQueue(client* clientListHead) {
    int position = 1;
    if (!clientListHead) {
        puts("Queue is empty");
        return;
    }
    printf("\n\n\n |Num||Surname||  Passport||   Account number   || Deposit sum|\n");
    do {
        printf(" |%3d|", position);
        clientListHead->position = position;
        position++;
        printf("|%7s|", clientListHead->surname);
        printf("|%10d||", clientListHead->pas_num);
        if (clientListHead->flag) {
            printf("               ");
            printf("     ||   %.2f    |", clientListHead->nor.depos_amount);

        } else {
            printf("   %12s     ||", clientListHead->nor.account_num);
            printf("            |");
        }
        printf("\n |------------------------------------------------------------|\n");
        clientListHead = clientListHead->next;// переход "вниз" к предыдущему эл-ту стека
    } while (clientListHead);
}
void
DeleteStructre(client **clientListHead, client** clientListTail) {//функция которая принимает вершину clientListHead
    if (!clientListHead) {
        puts("Queue is empty");
        return;
    }
    client* clientCur = *clientListHead;
    client* clientS = *clientListTail;
    int chooser = 0;
    chooser = checkNum(chooser);
    while (clientCur != NULL) {//пока указатель clientCur не пустой, мы его будем проверять, если он все же пусть цикл заканчивается
        if (clientCur->position == chooser) {//если position элемента равна числу, которое нам нужно удалить
            if (clientCur == *clientListHead) {//если такой указатель равен вершине, то есть элемент, который нам нужно удалить - вершина
                *clientListHead = clientCur->next;//передвигаем вершину на следующий элемент
                free(clientCur);//очищаем ячейку
            }
            else {
                if (!clientCur->next) {
                    *clientListTail = clientS;
                    clientS->next = NULL;
                }
                else {
                    clientS->next = clientCur->next;
                }
            }
        }// если chooser элемента НЕ равна числу, которое нам нужно удалить
        clientS = clientCur;
        clientCur = clientCur->next;
    }
}
void
FindQueue(client* clientList) {
    if(!clientList) {
        puts("Please enter structure");
        return;
    }
    char *name = NULL;
    int chooser = 0;
    printf("Enter a findind word/number");
    name = enterStr(name);
    do {

        printf("\n Enter: \n");
        printf("1-for finding by surname of bank\n");
        printf("2-for finding by number of passport\n");
        printf("3-for finding by account number\n");
        printf("4-for finding by deposit amount\n");
        printf("5-for exit\n");
        chooser = checkNum(chooser);

        switch (chooser) {
            case 1: {
                do {
                    if (!strCmp((clientList)->surname, name))
                        printCritter(clientList);
                    clientList = clientList->next;// переход "вниз" к предыдущему эл-ту стека
                } while (clientList);
                return;
            }
            case 2: {
                do {
                    if (clientList->pas_num == atoi(name))
                        printCritter(clientList);
                    clientList = clientList->next;// переход "вниз" к предыдущему эл-ту стека
                } while (clientList);
                return;
            }
            case 3: {
                do {
                    if (!clientList->flag)
                    if (!strCmp(clientList->nor.account_num, name))
                        printCritter(clientList);
                    clientList = clientList->next;// переход "вниз" к предыдущему эл-ту стека
                } while (clientList);
                return;
            }
            case 4: {
                do {
                    if (clientList->flag)   {
                        if ((int)(clientList->nor.depos_amount * 100) == atof(name)*100)
                            printCritter(clientList);
                }
                clientList = clientList->next;// переход "вниз" к предыдущему эл-ту стека
                } while (clientList);
                return;
            }
            case 5:
                return;
            default: {
                printf("Please try again\n");
                break;
            }
        }
    } while (1);

}
#pragma endregion

#pragma region File functionn
void
SaveBinary(client* clientList) {
    int amountOfElements = 0;
    char space = ' ';
    do {
        amountOfElements = 0;
        while (clientList->surname[amountOfElements] != '\0')
            fwrite(&clientList->surname[amountOfElements++], 1, 1, fileBin);
        fwrite(&clientList->surname[amountOfElements], 1, 1, fileBin);
        fwrite(&clientList->pas_num, sizeof(int), 1, fileBin);
        fwrite(&clientList->flag, sizeof(int), 1, fileBin);
        amountOfElements = 0;
        if (clientList->flag == 1) fwrite(&clientList->nor.depos_amount, sizeof(float), 1, fileBin);
        else {
            fwrite(&space, 1, 1, fileBin);
            while (clientList->nor.account_num[amountOfElements] != '\0')
                fwrite(&clientList->nor.account_num[amountOfElements++], 1, 1, fileBin);
            fwrite(&clientList->nor.account_num[amountOfElements], 1, 1, fileBin);
        }
        clientList = clientList->next;
    }while(clientList);
}
void
SaveTxt(client* clientList) {
    do {
        fprintf(fileTxt, "%s", clientList->surname);
        fprintf(fileTxt, "%c", '\0');
        fprintf(fileTxt, "%d ", clientList->pas_num);
        fprintf(fileTxt, "%1d ", clientList->flag);
        if (clientList->flag == 0) {
            fprintf(fileTxt, "%s", clientList->nor.account_num);
            fprintf(fileTxt, "%c", '\0');
        } else fprintf(fileTxt, "%.2f", clientList->nor.depos_amount);
        clientList = clientList->next;
    }while (clientList);
}
void
SaveInFile(client* clientList) {
    if(!clientList) {
        puts("Please enter structure");
        return;
    }
    int chooser = 0;
    do {
        printf("\n Enter: \n");
        printf("1-for text format\n");
        printf("2-for bynaric\n");
        printf("Other num - for exit\n");
        chooser = checkNum(chooser);
        switch (chooser) {
            case 1: {
                char* nameOFile = NULL;
                char folderOFile[] = folder;
                puts("Please enter a file name");
                strcat(folderOFile, enterStr(nameOFile));
                if (!(fileTxt = fopen(folderOFile, "w"))) {
                    puts("This file cannot be open, try again");
                    break;
                }
                SaveTxt(clientList);
                fclose(fileTxt);
                return;
            }
            case 2: {
                char* nameOFile = NULL;
                char folderOFile[] = folder;
                puts("Please enter a file name");
                strcat(folderOFile, enterStr(nameOFile));
                if (!(fileBin = fopen(folderOFile, "wb"))) {
                    puts("This file cannot be open, try again");
                    break;
                }
                SaveBinary(clientList);
                fclose(fileBin);
                return;
            }
            default: return;
        }
    }while(1);

}
void
LoadBinary(client** clientListHead, client** clientListTail) {
    client* clientList = NULL;
    char charBufer;
    int i;
    do {
        i = 0;
        if (!(clientList = (client*)calloc(1, sizeof(client))))
        {
            printf("Can't add one more structure");
            return;
        }
        //--------------Entering of surname--------------------
        fread(&charBufer, sizeof(char), 1, fileBin);
        (clientList)->surname = (char*)calloc(1, 1);
        while (charBufer != '\0') {
            (clientList)->surname = (char*)realloc((clientList)->surname, i + 1);
            (clientList)->surname[i] = charBufer;
            fread(&charBufer, sizeof(char), 1, fileBin);
            i++;
        }
        (clientList)->surname[i] = charBufer;
        i = 0;
        //--------------Entering a passport-----------------------------
        fread(&(clientList)->pas_num, sizeof(int), 1, fileBin);
        if (feof(fileBin)) {
            fclose(fileBin);
            clientList = clientList;
            return;
        }
        //--------------Entering of deposit  or account num------
        fread(&(clientList)->flag, sizeof(int), 1, fileBin);
        if ((clientList)->flag == 1) fread(&(clientList)->nor.depos_amount, sizeof(float), 1, fileBin);
        else {
            fread(&charBufer, sizeof(char), 1, fileBin);
            fread(&charBufer, sizeof(char), 1, fileBin);
            (clientList)->nor.account_num = (char*)calloc(1, 1);
            while (charBufer != '\0') {
                (clientList)->nor.account_num = (char*)realloc((clientList)->nor.account_num, i + 1);
                (clientList)->nor.account_num[i] = charBufer;
                fread(&charBufer, sizeof(char), 1, fileBin);
                i++;
            }
            (clientList)->nor.account_num[i] = charBufer;
        }
        if (!*clientListHead) {
            *clientListTail = *clientListHead = clientList;
        }
        else {
            (*clientListTail)->next = clientList;
            (*clientListTail) = clientList;
        }
    } while (!feof(fileBin));
    clientList->next = NULL;
    fclose(fileBin);
}
void
LoadText(client** clientListHead, client** clientListTail) {
    client* clientList = NULL;
    char charBufer;
    int i;
    do {
        i = 0;
        if (!(clientList = (client*)calloc(1, sizeof(client))))
        {
            printf("Can't add one more structure");
            return;
        }
        //--------------Entering of surname--------------------

        fscanf(fileTxt, "%c", &charBufer);
        (clientList)->surname = (char*)calloc(1, 1);

        while (charBufer != '\0') {
            (clientList)->surname = (char*)realloc((clientList)->surname, i+1);
            (clientList)->surname[i++] = charBufer;
            fscanf(fileTxt, "%c", &charBufer);
        }
        (clientList)->surname[i++] = charBufer;
        i = 0;
        //--------------Entering a passport-----------------------------
        fscanf(fileTxt, "%d", &(clientList)->pas_num);
        if (feof(fileTxt)) {
            fclose(fileTxt);
            clientList = clientList;
            return;
        }
        //--------------Entering of deposit  or account num------
        fscanf(fileTxt, "%1d", &(clientList)->flag);
        if ((clientList)->flag == 1) fscanf(fileTxt, "%f", &(clientList)->nor.depos_amount);
        else {
            fread(&charBufer, sizeof(char), 1, fileTxt);
            fread(&charBufer, sizeof(char), 1, fileTxt);
            (clientList)->nor.account_num = (char*)calloc(1, 1);
            while (charBufer != '\0') {
                (clientList)->nor.account_num = (char*)realloc((clientList)->nor.account_num, i + 1);
                (clientList)->nor.account_num[i++] = charBufer;
                fscanf(fileTxt, "%c", &charBufer);
            }
            (clientList)->nor.account_num[i] = charBufer;
        }
        clientList->next = clientList;
        if (!*clientListHead) {
            *clientListTail = *clientListHead = clientList;
        }
        else {
            (*clientListTail)->next = clientList;
            (*clientListTail) = clientList;
        }
    } while (!feof(fileTxt));
    clientList->next = NULL;
    fclose(fileTxt);
}
void
LoadInFile(client** clientListHead, client** clientListTail) {
    *clientListTail = *clientListHead = NULL;
    int chooser = 0;
    do {
        printf("\n Enter: \n");
        printf("1-in text format\n");
        printf("2-in bynaric\n");
        printf("Other num - for exit\n");
        chooser = checkNum(chooser);
        switch (chooser) {
            case 1: {
                char* nameOFile = NULL;
                char folderOFile[] = folder;
                puts("Please enter a file name");
                strcat(folderOFile, enterStr(nameOFile));
                if(!(fileTxt = fopen(folderOFile,"r"))) {
                    puts("This file cannot be open, try again");
                    break;
                }
                LoadText(clientListHead,clientListTail);
                return;
            }
            case 2: {
                char* nameOFile = NULL;
                char folderOFile[] = folder;
                puts("Please enter a file name");
                strcat(folderOFile, enterStr(nameOFile));
                if (!(fileBin = fopen(folderOFile, "rb"))) {
                    puts("This file cannot be open, try again");
                    break;
                }
                LoadBinary(clientListHead,clientListTail);
                return;
            }
            default: return;
        }
    }while(1);

}
#pragma endregion


void
menu(client* clientListHead, client* clientListTail) {
    int chooser = 0;
    do {
        printf("\n Enter: \n");
        printf("1-for enter struct\n");
        printf("2-for print struct\n");
        printf("3-for searching in struct\n");
        printf("4-for deleting struct\n");
        printf("5-for saving structure in file\n");
        printf("6-for loading structure from file\n");
        printf("Other num - for exit\n");

        chooser = checkNum(chooser);
        switch (chooser) {
            case 1: {
                EnterStructure(&clientListHead,&clientListTail);
                break;
            }
            case 2: {
                ShowQueue(clientListHead);
                break;
            }
            case 3: {
                FindQueue(clientListHead);
                break;
            }
            case 4:
                DeleteStructre(&clientListHead,&clientListTail);
                break;
            case 5:
                SaveInFile(clientListHead);
                break;
            case 6:
                LoadInFile(&clientListHead,&clientListTail);
                break;
            default: return;
        }
    } while (1);
}

int main() {
    client* clientListHead = NULL;
    client* clientListTail = clientListHead;
    menu(clientListHead,clientListTail);
    free(clientListHead);
    free(clientListTail);
    return 0;
}