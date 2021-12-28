#ifndef GRADESTUDENT_H
#define GRADESTUDENT_H

#include "Student.h"

class GradeStudent : public Student {
   protected:
    string m_workpl;

   public:
    GradeStudent(const string name = "George", const int age = 23,
                 const int course = 4, const string workplc = "Google");
    string getWorkpl() override { return m_workpl; }
    void setWorkpl(string workpl) { m_workpl = workpl; }
    string type() override { return "GradeStudent"; }
    int getCourse() override { return m_course; }
    int getGrade() override { return 0; }
    ostream& print(ostream& out) const override;
    ~GradeStudent() override;
};

#endif