#ifndef GOODSCHOOLKID_H
#define GOODSCHOOLKID_H

#include "SchoolKid.h"

class GoodSchoolKid : public SchoolKid {
   protected:
    string m_book;

   public:
    GoodSchoolKid(const string name = "Oleg", const int age = 14,
                             const int grade = 5,
                             const string book = "Harry Potter");
    ~GoodSchoolKid();
    string getBook() { return m_book; }
    ostream& print(ostream& out) const override;
};
#endif