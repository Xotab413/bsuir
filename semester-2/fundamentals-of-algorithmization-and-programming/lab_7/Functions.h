#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>



#define MAX_WORD_SIZE 17

typedef  struct tree {
    char englishWord[MAX_WORD_SIZE];
    char russianWord[MAX_WORD_SIZE];
    struct tree* leftBranch;
    struct tree* rightBranch;
}tree;
void treeInput(tree**);

void menu(tree**);

int strcmpIgnoreCase(const char*, const char*);

void printBasic(tree* dr);

tree* deleting(tree*);

void treeDestroy(tree*);

void printWithStack(tree*);

void getsByMe(char*, int);
#endif	

