#include "../headers/Professor.h"

Professor::Professor(const string name, const int age,
                     const int grade, const string book,
                     const int course, const string worlpl,
                     const int salary)
    : Pupil(name, age),
      GoodSchoolKid(name, age, grade, book),
      GradeStudent(name, age, course, worlpl),
      m_salary{salary} {}

Professor::~Professor() {}

ostream& Professor::print(ostream& out) const {
    out << "Name = " << m_name << endl
        << "Age = " << m_age << endl
        << "Grade = " << m_grade << endl
        << "Course = " << m_course << endl
        << "Favorite book = " << m_book << endl
        << "Workplace = " << m_workpl << endl
        << "Salary = " << m_salary << "$" << endl;
    return out;
}