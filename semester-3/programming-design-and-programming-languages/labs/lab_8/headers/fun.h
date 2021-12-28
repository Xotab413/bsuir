#ifndef FUNC_H
#define FUNC_H

#include "Set.h"

int checkNum();
Set enterOneSet();
void printSets(const vector<Set>& set_v);

//--------------------------------------------------
void findSeq(const vector<Set>& set_v);
void deleteSet(vector<Set>& set_v);
void deleteDupl(vector<Set>& set_v);
void unificationSets(vector<Set>& set_v);
void intersectionSets(vector<Set>& set_v);
void CopyToPosition(vector<Set>& set_v);
//--------------------------------------------------

// -__-
inline void printMenu();
vector<Set> getTempl();
void mainMenu();
#endif