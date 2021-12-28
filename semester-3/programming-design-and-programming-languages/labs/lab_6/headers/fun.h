#ifndef FUNC_H
#define FUNC_H
#include "GradeStudent.h"
#include "SchoolKid.h"

int checkNum();
string enterStr();

GradeStudent enterOneGradeStudent();
Student enterOneStudent();
SchoolKid enterOneSchoolKid();

void menuCreation();
void findMenu();
void createPupils(Pupil**& mas, int& size);

//--------------------------------------------------
void findName(Pupil**& mas, const int size);
void findWorkpl(Pupil**& mas, const int size);
void findGrade(Pupil**& mas, const int size);
void findCourse(Pupil**& mas, const int size);
void findAge(Pupil**& mas, const int size);
void findPupils(Pupil**& mas, const int size);
//--------------------------------------------------

void deleteOnce(Pupil**& mas, int& size, int del_pos);
void deleteDuplicate(Pupil**& mas, int& size);

void prntPupils(Pupil** arr, const int size);
void printMenu();

void getTempl(Pupil**& mas, int& size);

void mainMenu();
#endif