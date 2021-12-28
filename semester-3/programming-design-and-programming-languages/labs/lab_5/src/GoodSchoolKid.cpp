#include "../headers/GoodSchoolKid.h"

GoodSchoolKid::GoodSchoolKid(const string name, const int age,
                             const int grade,
                             const string book)
    : Pupil(name, age), SchoolKid(name, age, grade), m_book(book) {}

GoodSchoolKid::~GoodSchoolKid() { m_book.clear(); }

ostream& GoodSchoolKid::print(ostream& out) const {
    out << "Name = " << m_name << endl
        << "Age = " << m_age << endl
        << "Grade = " << m_grade << endl
        << "Favorite book = " << m_book << endl;
    return out;
}