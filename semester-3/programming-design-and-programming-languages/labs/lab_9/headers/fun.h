#ifndef FUNC_H
#define FUNC_H
#include <limits>
#include <fstream>


int checkNum();



void printFileType();
void printMenu();
void DeleteDuplicate();
void FindRangeTxT(const std::string path);
void FindRangeBin(const std::string path);
void sortBin(const std::string path);
void sortTxT(const std::string path);
void mainMenu();

#endif