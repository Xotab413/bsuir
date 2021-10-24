

#ifndef SEM_2_STACK_H
#define SEM_2_STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char folder[] = "C:\\Semen\\BSIIR\\OAIP\\sem_2\\lab_6\\";

#pragma region File
FILE* fileTxt ;
FILE* fileBin ;
#pragma endregion

union nums {
    char* account_num;
    float depos_amount;
};

typedef struct client_database {
    unsigned int position;
    char* surname;
    int pas_num;
    union nums nor;
    int flag;
}client;

typedef struct Container {
    struct Container* previous;
    struct Container* next;
    client client_inf;
}container;


#endif //SEM_2_STACK_H
