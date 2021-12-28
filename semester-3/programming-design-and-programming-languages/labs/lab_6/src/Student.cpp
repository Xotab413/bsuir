#include "../headers/Student.h"

Student::Student(const string name, const int age, const int course)
    : Pupil(name, age), m_course{course} {}

Student::~Student() {}

ostream& Student::print(ostream& out) const {
    out << "Name = " << m_name << endl
        << "Age = " << m_age << endl
        << "Course = " << m_course << endl;
    return out;
}