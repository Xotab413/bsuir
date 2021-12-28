#ifndef FUNC_HPP
#define FUNC_HPP
#include "Memorial.h"
#include "vector"
using namespace memorial;

string enterStr();
float checkDbl();
int checkNum();
Memorial enterOneMemorial();

void descAsc();
void menuSort();

// COMPARATORS
bool compName(Memorial left, Memorial right);
bool compSurname(Memorial left, Memorial right);
bool compCoordinate(Memorial left, Memorial right);
bool compPriceMaterial(Memorial left, Memorial right);
bool compTitleMaterial(Memorial left, Memorial right);
bool compWhom(Memorial left, Memorial right);
bool compHonor(Memorial left, Memorial right);
bool compHeight(Memorial left, Memorial right);
bool compSquare(Memorial left, Memorial right);

// NOT COMPARATORS
bool noTcompName(Memorial left, Memorial right);
bool noTcompSurname(Memorial left, Memorial right);
bool noTcompCoordinate(Memorial left, Memorial right);
bool noTcompPriceMaterial(Memorial left, Memorial right);
bool noTcompTitleMaterial(Memorial left, Memorial right);
bool noTcompWhom(Memorial left, Memorial right);
bool noTcompHonor(Memorial left, Memorial right);
bool noTcompHeight(Memorial left, Memorial right);
bool noTcompSquare(Memorial left, Memorial right);
//--------------------------------------------------
// FINDING
void findName( const vector<Memorial>& memr_v);
void findSurname( const vector<Memorial>& memr_v);
void findCoordinate( const vector<Memorial>& memr_v);
void findPriceMaterial( const vector<Memorial>& memr_v);
void findTitleMaterial(const vector<Memorial>& memr_v);
void findWhom( const vector<Memorial>& memr_v);
void findHonor( const vector<Memorial>& memr_v);
void findHeight( const vector<Memorial>& memr_v);
void findSquare( const vector<Memorial>& memr_v);
//--------------------------------------------------
void sortMemorial(vector<Memorial>& memr_v);
void findMemorial( const vector<Memorial>& memr_v);




//--------------------------------------------------
void deleteMemorial(vector<Memorial>& memr_v);
void deleteDupl( vector<Memorial>& memr_v);
void CopyToPosition( vector<Memorial>& memr_v);
//--------------------------------------------------

// -__-
inline void printMenu();
void printMemorial(const vector<Memorial>& memr_v);
void mainMenu();
#endif