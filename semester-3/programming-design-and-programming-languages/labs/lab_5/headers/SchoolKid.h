#ifndef SCHOOLKID_H
#define SCHOOLKID_H

#include "Pupil.h"

class SchoolKid : virtual public Pupil {
   protected:
    int m_grade;

   public:
    SchoolKid(const string name = "Petya", const int age = 10,
              const int grade = 3);
    ~SchoolKid();
    int getGrade() { return m_grade; }
    virtual ostream& print(ostream& out) const override;
};
#endif