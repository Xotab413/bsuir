#ifndef GRADESTUDENT_H
#define GRADESTUDENT_H

#include "Student.h"

class GradeStudent : public Student {
   protected:
    string m_workpl;

   public:
    GradeStudent(const string name = "George", const int age = 23,
                 const int course = 4, const string workplc = "Google");
    ~GradeStudent();
    string getWorkpl() { return m_workpl; }
    ostream& print(ostream& out) const override;
};

#endif