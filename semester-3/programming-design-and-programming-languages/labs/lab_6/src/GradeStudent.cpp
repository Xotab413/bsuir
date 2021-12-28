#include "../headers/GradeStudent.h"
GradeStudent::GradeStudent(const string name, const int age, const int course,
                           const string workplc)
    : Pupil(name, age), Student(name, age, course), m_workpl{workplc} {}

GradeStudent::~GradeStudent() {}

ostream& GradeStudent::print(ostream& out) const{
    out << "Name = " << m_name << endl
        << "Age = " << m_age << endl
        << "Course = " << m_course << endl
        << "Workplace = " << m_workpl << endl;
    return out;
}
