

#ifndef SEM_2_STACK_H
#define SEM_2_STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#define folder "C:\\Semen\\BSIIR\\OAIP\\sem_2\\lab_4\\";

#pragma region File
FILE* fileTxt = NULL;
FILE* fileBin = NULL;
#pragma endregion

union nums {
    char* account_num;
    float depos_amount;
};
typedef struct client_database {
    unsigned char position;
    char* surname;
    int pas_num;
    union nums nor;
    int flag;
    struct client_database *next;
}client;


#endif //SEM_2_STACK_H
