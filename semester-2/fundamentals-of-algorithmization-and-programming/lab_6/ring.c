#include "ring.h"
#pragma warning(disable : 4996)
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
strCmp(const char *s1, const char *s2) {
    while (*s2 && *s1 && (*s1 == *s2 || *s1 == *s2 - 32 || *s1 == *s2 + 32)) ++s1, ++s2;
    return (*s1 > *s2 ? 1 : (*s1 < *s2 ? -1 : 0));
}

int
checkNum(int num) {
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
printCritter(container *c) {
    if (c->client_inf.flag)
        printf("\nSurname: %s\t Passport number : %d\t Account number or Deposit sum : %f \n", c->client_inf.surname, c->client_inf.pas_num,
               c->client_inf.nor.depos_amount);
    else
        printf("\nSurname: %s\t Passport number : %d\t Account number or Deposit sum : %s \n", c->client_inf.surname, c->client_inf.pas_num,
               c->client_inf.nor.account_num);
}

void
printBar() {
    printf("\n\n\n |Num||Surname||  Passport||   Account number   || Deposit sum|\n");
}

#pragma endregion

#pragma region Queue function

void
EnterStructure(container **clientList) {
    int chooser = 0;
    container *pDatabase1;
    if (*clientList == NULL) {
        if (!(pDatabase1 = (container *) calloc(1, sizeof(client)))) {
            puts("Not enough memory");
            return;
        }
#pragma region Create
        puts("Enter surname of client");
        enterSurname(&pDatabase1->client_inf);
        puts("Enter passport number");
        checkPass(&pDatabase1->client_inf);
        puts("Enter 1 - for entering deposit sum, 2 - for entering account num");

        do {
            chooser = checkNum(chooser);

            if (chooser == 1) {
                (&pDatabase1->client_inf)->flag = 1;
                puts("Enter a deposit sum");
                checkDeposSum(&pDatabase1->client_inf);
                break;
            }
            if (chooser == 2) {
                (&pDatabase1->client_inf)->flag = 0;
                puts("Enter Account num");
                enterAccNum(&pDatabase1->client_inf);
                break;
            } else {
                puts("Try again");
            }
        } while (1);
#pragma endregion
        pDatabase1->previous = pDatabase1;
        pDatabase1->next = pDatabase1;
        *clientList = pDatabase1;
    } else {
        if (!(pDatabase1 = (container *) calloc(1, sizeof(client)))) {
            puts("Not enough memory");
            return;
        }
        do {
            printf("1 - add to end(queue))\n2 - add to start(stack)(default)\n(Wrong option == default) Enter option: ");
            rewind(stdin);
            if (getchar() == '2') {
#pragma region Create
                puts("Enter surname of client");
                enterSurname(&pDatabase1->client_inf);
                puts("Enter passport number");
                checkPass(&pDatabase1->client_inf);
                puts("Enter 1 - for entering deposit sum, 2 - for entering account num");

                do {
                    chooser = checkNum(chooser);

                    if (chooser == 1) {
                        (&pDatabase1->client_inf)->flag = 1;
                        puts("Enter a deposit sum");
                        checkDeposSum(&pDatabase1->client_inf);
                        break;
                    }
                    if (chooser == 2) {
                        (&pDatabase1->client_inf)->flag = 0;
                        puts("Enter Account num");
                        enterAccNum(&pDatabase1->client_inf);
                        break;
                    } else {
                        puts("Try again");
                    }
                } while (1);
#pragma endregion
                pDatabase1->next = *clientList;
                pDatabase1->previous = clientList[0]->previous;
                clientList[0]->previous = pDatabase1;
                pDatabase1->previous->next = pDatabase1;
                *clientList = pDatabase1;
            } else {
#pragma region Create
                puts("Enter surname of client");
                enterSurname(&pDatabase1->client_inf);
                puts("Enter passport number");
                checkPass(&pDatabase1->client_inf);
                puts("Enter 1 - for entering deposit sum, 2 - for entering account num");

                do {
                    chooser = checkNum(chooser);

                    if (chooser == 1) {
                        (&pDatabase1->client_inf)->flag = 1;
                        puts("Enter a deposit sum");
                        checkDeposSum(&pDatabase1->client_inf);
                        break;
                    }
                    if (chooser == 2) {
                        (&pDatabase1->client_inf)->flag = 0;
                        puts("Enter Account num");
                        enterAccNum(&pDatabase1->client_inf);
                        break;
                    } else {
                        puts("Try again");
                    }
                } while (1);
#pragma endregion
                pDatabase1->previous = clientList[0]->previous;
                clientList[0]->previous = pDatabase1;
                pDatabase1->previous->next = pDatabase1;
                pDatabase1->next = *clientList;
            }
            puts("One more? (y/n)");
            fflush(stdin);
        } while (getchar() == 'y');
    }
}
void
ShowRing(container *clientList) {
    container *temp;
    char chooser = 0;
    int position = 1;
    if (!clientList) {
        puts("Ring is empty");
        return;
    }
    temp = clientList;

    puts("1 - as stack, 2 - as  queue\n");
    fflush(stdin);
    chooser = checkNum(chooser);
    switch (chooser) {
        case 1: {
            temp = temp->previous;
            printf("\n\n\n |Num||Surname||  Passport||   Account number   || Deposit sum|\n");
#pragma region Show
            do  {
                temp->client_inf.position = position;
                printf(" |%3d|", position);
                position++;
                printf("|%7s|", temp->client_inf.surname);
                printf("|%10d||", temp->client_inf.pas_num);
                if (temp->client_inf.flag) {
                    printf("               ");
                    printf("     ||   %.2f    |", temp->client_inf.nor.depos_amount);

                } else {
                    printf("   %12s     ||", temp->client_inf.nor.account_num);
                    printf("            |");
                }
                printf("\n |------------------------------------------------------------|\n");
                temp = temp->previous;
            }while (temp!=clientList->previous);
#pragma endregion
            break;
        }
        case 2: {
            printf("\n\n\n |Num||Surname||  Passport||   Account number   || Deposit sum|\n");
#pragma region Show
            do {
                printf(" |%3d|", position);
                temp->client_inf.position = position;
                position++;
                printf("|%7s|", temp->client_inf.surname);
                printf("|%10d||", temp->client_inf.pas_num);
                if (temp->client_inf.flag) {
                    printf("               ");
                    printf("     ||   %.2f    |", temp->client_inf.nor.depos_amount);

                } else {
                    printf("   %12s     ||", temp->client_inf.nor.account_num);
                    printf("            |");
                }
                printf("\n |------------------------------------------------------------|\n");
                temp = temp->next;
            } while (temp != clientList);
#pragma endregion
            break;
        }
    }
}
container*
DeleteStructre(container *clientList) {
    if (!clientList) {
        puts("ring is empty");
        return NULL;
    }
    container *temp = clientList;
    int chooser = 0;
    chooser = checkNum(chooser);
    do {
        if (temp->client_inf.position == chooser) {
            if (clientList->next == clientList) {
                clientList = NULL;
                return clientList;
            }
            else {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                return temp->next;
            }
        }
        temp = temp->next;
    } while (temp != clientList);
}

void
FindRing(container *clientList) {
    container *temp = clientList;
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
                    if (!strCmp((temp)->client_inf.surname, name))
                        printCritter(temp);
                    temp = temp->next;
                } while (temp!=clientList);
                return;
            }
            case 2: {
                do {
                    if (temp->client_inf.pas_num == atoi(name))
                        printCritter(temp);
                    temp = temp->next;
                } while (temp!=clientList);
                return;
            }
            case 3: {

                do {
                    if (!strCmp(temp->client_inf.nor.account_num, name))
                        printCritter(temp);
                    temp = temp->next;
                } while (temp!=clientList);
                return;
            }
            case 4: {
                do {
                    if ((int)(temp->client_inf.nor.depos_amount * 100) == atof(name)*100)
                        printCritter(temp);
                    temp = temp->next;
                } while (temp!=clientList);
                return;
            }
            case 5:
                return;
            default: {
                printf("Please try again\n");
                return;
            }
        }
    } while (1);

}
#pragma endregion

#pragma region File functionn

void
SaveBinary(container *clientList) {
    container *temp = clientList;
    int amountOfElements;
    do {
        amountOfElements = 0;
        while (temp->client_inf.surname[amountOfElements] != '\0')
            fwrite(&temp->client_inf.surname[amountOfElements++], 1, 1, fileBin);
        fwrite(&temp->client_inf.surname[amountOfElements], 1, 1, fileBin);
        fwrite(&temp->client_inf.pas_num, sizeof(int), 1, fileBin);
        fwrite(&temp->client_inf.flag, sizeof(int), 1, fileBin);
        amountOfElements = 0;
        if (temp->client_inf.flag == 1)
            fwrite(&temp->client_inf.nor.depos_amount, sizeof(float), 1, fileBin);
        else {
            while (temp->client_inf.nor.account_num[amountOfElements] != '\0')
                fwrite(&temp->client_inf.nor.account_num[amountOfElements++], 1, 1, fileBin);
            fwrite(&temp->client_inf.nor.account_num[amountOfElements], 1, 1, fileBin);
        }
        temp = temp->next;
    } while (temp != clientList);
}

void
SaveTxt(container *clientList) {
    container *temp = clientList;
    do {
        fprintf(fileTxt, "%s", temp->client_inf.surname);
        fprintf(fileTxt, "%c", '\0');
        fprintf(fileTxt, "%d ", temp->client_inf.pas_num);
        fprintf(fileTxt, "%1d ", temp->client_inf.flag);
        if (temp->client_inf.flag == 0) {
            fprintf(fileTxt, "%s", temp->client_inf.nor.account_num);
            fprintf(fileTxt, "%c", '\0');
        } else fprintf(fileTxt, "%.2f", temp->client_inf.nor.depos_amount);
        temp = temp->next;
    } while (temp != clientList);
}

void
SaveInFile(container *clientList) {
    if (!clientList) {
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
                char *nameOFile = NULL;
                char *folderOFile = NULL;
                folderOFile = (char*)calloc(33, 1);
                strcpy(folderOFile, folder);
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
                char *nameOFile = NULL;
                char *folderOFile = NULL;
                folderOFile = (char*)calloc(33, 1);
                strcpy(folderOFile, folder);
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
            default:
                return;
        }
    } while (1);
    return;
}
void
LoadBinOne(container *clientList) {
    char charBufer;
    int i = 0;
    //--------------Entering of surname--------------------

    fread(&charBufer, sizeof(char), 1, fileBin);
    (clientList)->client_inf.surname = (char *) calloc(1, 1);

    while (charBufer != '\0') {
        (clientList)->client_inf.surname = (char *) realloc((clientList)->client_inf.surname, i + 1);
        (clientList)->client_inf.surname[i++] = charBufer;
        fread(&charBufer, sizeof(char), 1, fileBin);
    }
    (clientList)->client_inf.surname[i] = charBufer;
    i = 0;
    //--------------Entering a passport-----------------------------
    fread(&(clientList)->client_inf.pas_num, sizeof(int), 1, fileBin);
    if (feof(fileBin)) {
        fclose(fileBin);
        clientList = clientList;
        return;
    }
    //--------------Entering of deposit  or account num------
    fread(&(clientList)->client_inf.flag, sizeof(int), 1, fileBin);
    if ((clientList)->client_inf.flag == 1)
        fread(&(clientList)->client_inf.nor.depos_amount, sizeof(float), 1, fileBin);
    else {
        fread(&charBufer, sizeof(char), 1, fileBin);
        (clientList)->client_inf.nor.account_num = (char *) calloc(1, 1);
        while (charBufer != '\0') {
            (clientList)->client_inf.nor.account_num = (char *) realloc((clientList)->client_inf.nor.account_num,i + 1);
            (clientList)->client_inf.nor.account_num[i++] = charBufer;
            fread(&charBufer, sizeof(char), 1, fileBin);
        }
        (clientList)->client_inf.nor.account_num[i] = charBufer;
    }
}
void
LoadBinary(container **clientDatabase) {
    *clientDatabase = NULL;
    container *clientList = NULL;
    fpos_t curPos = 0,endPos = 0;
    fseek(fileBin,0,2);
    fgetpos(fileBin,&endPos);
    fseek(fileBin,0,0);
    if (!(clientList = (container*) calloc(1, sizeof(container)))) {
        puts("Not enough memory");
        return;
    }
    LoadBinOne(clientList);
    clientList->previous = clientList;
    clientList->next = clientList;
    *clientDatabase = clientList;
    do {
        fgetpos(fileBin,&curPos);
        if(curPos==endPos)
            break;
        if (!(clientList = (container*) calloc(1, sizeof(container)))) {
            puts("Not enough memory");
            return;
        }
        LoadBinOne(clientList);
        clientList->next = *clientDatabase;
        clientList->previous = clientDatabase[0]->previous;
        clientDatabase[0]->previous = clientList;
        clientList->previous->next = clientList;
    } while (1);
    fclose(fileBin);
}
void
LoadTextOne(container* clientList) {
    char charBufer;
    int i = 0;
    //--------------Entering of surname--------------------
    fscanf(fileTxt, "%c", &charBufer);
    (clientList)->client_inf.surname = (char *) calloc(1, 1);

    while (charBufer != '\0') {
        (clientList)->client_inf.surname = (char *) realloc((clientList)->client_inf.surname, i + 1);
        (clientList)->client_inf.surname[i++] = charBufer;
        fscanf(fileTxt, "%c", &charBufer);
    }
    (clientList)->client_inf.surname[i++] = charBufer;
    i = 0;
    //--------------Entering a passport-----------------------------
    fscanf(fileTxt, "%d", &(clientList)->client_inf.pas_num);
    if (feof(fileTxt)) {
        fclose(fileTxt);
        clientList = clientList;
        return;
    }
    //--------------Entering of deposit  or account num------
    fscanf(fileTxt, "%1d", &(clientList)->client_inf.flag);
    if ((clientList)->client_inf.flag == 1) fscanf(fileTxt, "%f", &(clientList)->client_inf.nor.depos_amount);
    else {
        rewind(stdin);
        fscanf(fileTxt, "%c", &charBufer);
        fscanf(fileTxt, "%c", &charBufer);
        (clientList)->client_inf.nor.account_num = (char *) calloc(1, 1);
        while (charBufer != '\0') {
            (clientList)->client_inf.nor.account_num = (char *) realloc((clientList)->client_inf.nor.account_num,i + 1);
            (clientList)->client_inf.nor.account_num[i++] = charBufer;
            fscanf(fileTxt, "%c", &charBufer);
        }
        (clientList)->client_inf.nor.account_num[i] = charBufer;
    }
}
void
LoadText(container **clientDatabase) {
    *clientDatabase = NULL;
    container *clientList = NULL;
    fpos_t curPos = 0,endPos = 0;
    fseek(fileTxt,0,2);
    fgetpos(fileTxt,&endPos);
    fseek(fileTxt,0,0);
    if (!(clientList = (container*) calloc(1, sizeof(container)))) {
        puts("Not enough memory");
        return;
    }
    LoadTextOne(clientList);
    clientList->previous = clientList;
    clientList->next = clientList;
    *clientDatabase = clientList;
    do {
        fgetpos(fileTxt,&curPos);
        if(curPos==endPos)
            break;
        if (!(clientList = (container*) calloc(1, sizeof(container)))) {
            puts("Not enough memory");
            return;
        }
        LoadTextOne(clientList);

        clientList->next = *clientDatabase;
        clientList->previous = clientDatabase[0]->previous;
        clientDatabase[0]->previous = clientList;
        clientList->previous->next = clientList;
    } while (1);
    fclose(fileTxt);
}

void
LoadInFile(container **clientList) {
    int chooser = 0;
    do {
        printf("\n Enter: \n");
        printf("1-in text format\n");
        printf("2-in bynaric\n");
        printf("Other num - for exit\n");
        chooser = checkNum(chooser);
        switch (chooser) {
            case 1: {
                char *nameOFile = NULL;
                char *folderOFile = NULL;
                folderOFile = (char*)calloc(33, 1);
                strcpy(folderOFile, folder);
                puts("Please enter a file name");
                strcat(folderOFile, enterStr(nameOFile));
                if (!(fileTxt = fopen(folderOFile, "r"))) {
                    puts("This file cannot be open, try again");
                    break;
                }
                LoadText(clientList);
                return;
            }
            case 2: {
                char *nameOFile = NULL;
                char *folderOFile = NULL;
                folderOFile = (char*)calloc(33, 1);
                strcpy(folderOFile, folder);
                puts("Please enter a file name");
                strcat(folderOFile, enterStr(nameOFile));
                if (!(fileBin = fopen(folderOFile, "rb"))) {
                    puts("This file cannot be open, try again");
                    break;
                }
                LoadBinary(clientList);
                return;
            }
            default:
                return;
        }
    } while (1);

}

#pragma endregion


void
menu(container **clientList) {
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
                EnterStructure(clientList);
                break;
            }
            case 2: {
                ShowRing(*clientList);
                break;
            }
            case 3: {
                FindRing(*clientList);
                break;
            }
            case 4:
                *clientList = DeleteStructre(*clientList);
                break;
            case 5:
                SaveInFile(*clientList);
                break;
            case 6:
                LoadInFile(clientList);
                break;
            default:
                return;
        }
    } while (1);
}

int main() {
    container *clientList = NULL;
    menu(&clientList);
    free(clientList);
    return 0;
}