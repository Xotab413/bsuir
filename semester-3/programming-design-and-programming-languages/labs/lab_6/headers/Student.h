#ifndef STUDENT_H
#define STUDENT_H

#include "Pupil.h"

class Student : virtual public Pupil {
   protected:
    int m_course;

   public:
    Student(const string name = "Vasya", const int age = 17,
            const int course = 1);
    int getCourse() override { return m_course; }
    void setCourse(int course) { m_course = course; }
    virtual ostream& print(ostream& out) const override;
    string type() override { return "Student"; }
    string getWorkpl() override { return "Not yet)"; }
    int getGrade() override { return 0; }
    ~Student() override;
};
#endif