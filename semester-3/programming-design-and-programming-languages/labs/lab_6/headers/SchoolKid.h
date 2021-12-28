#ifndef SCHOOLKID_H
#define SCHOOLKID_H

#include "Pupil.h"

class SchoolKid : virtual public Pupil {
   protected:
    int m_grade;

   public:
    SchoolKid(const string name = "Petya", const int age = 10,
              const int grade = 3);
    int getGrade() override { return m_grade; }
    void setGrade(int grade) { m_grade = grade; }
    virtual string type() override { return "SchoolKid"; }
    virtual string getWorkpl() override { return "I'm a kid, i'dont work at all"; }
    virtual int getCourse() override { return 0; }
    virtual ostream& print(ostream& out) const override;
    ~SchoolKid() override;
};
#endif