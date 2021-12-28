#include "../headers/SchoolKid.h"
SchoolKid::SchoolKid(const string name, const int age, const int grade)
    : Pupil(name, age), m_grade{grade} {}

SchoolKid::~SchoolKid() {}

ostream& SchoolKid::print(ostream& out) const{
    out << "Name = " << m_name << endl
        << "Age = " << m_age << endl
        << "Grade = " << m_grade << endl;
    return out;
}