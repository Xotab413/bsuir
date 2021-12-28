#ifndef STUDENT_H
#define STUDENT_H

#include "Pupil.h"

class Student : virtual public Pupil {
   protected:
    int m_course;

   public:
    Student(const string name = "Vasya", const int age = 17,
            const int course = 1);
    ~Student();
    int getCourse() { return m_course; }
    virtual ostream& print(ostream& out) const override;
};

#endif