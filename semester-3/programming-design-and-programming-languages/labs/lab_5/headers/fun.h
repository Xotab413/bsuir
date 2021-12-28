#ifndef FUNC_H
#define FUNC_H

#include "Professor.h"
#include <algorithm>
#include <vector>

int checkNum();
string enterStr();
Professor enterOneProfesor();

inline void descAsc();
inline void menuSort();

// COMPARATORS
inline bool compAge(Professor left, Professor right);
inline bool compSalary(Professor left, Professor right);
inline bool compGrade(Professor left, Professor right);
inline bool compCourse(Professor left, Professor right);
inline bool compName(Professor left, Professor right);
inline bool compWorkpl(Professor left, Professor right);
inline bool compBooks(Professor left, Professor right);

// THE SAME AS UPPER BUT WITH NOT
inline bool noTcompSalary(Professor left, Professor right);
inline bool noTcompGrade(Professor left, Professor right);
inline bool noTcompCourse(Professor left, Professor right);
inline bool noTcompName(Professor left, Professor right);
inline bool noTcompWorkpl(Professor left, Professor right);
inline bool noTcompBooks(Professor left, Professor right);
inline bool noTcompAge(Professor left, Professor right);

// FINDING
void findName(const std::vector<Professor>& pr_v);
void findBook(const std::vector<Professor>& pr_v);
void findWorkpl(const std::vector<Professor>& pr_v);
void findGrade(const std::vector<Professor>& pr_v);
void findCourse(const std::vector<Professor>& pr_v);
void findSalary(const std::vector<Professor>& pr_v);
void findAge(const std::vector<Professor>& pr_v);

//--------------------------------------------------

void sortProfrs(vector<Professor>& pr_v);
void prntProfesr(const vector<Professor>& professors);
void findProfrs(const std::vector<Professor>& pr_v);
inline void printMenu();
inline void prntOther();
vector<Professor> getTempl();
void mainMenu();
#endif