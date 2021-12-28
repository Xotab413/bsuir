#ifndef PUPIL_H
#define PUPIL_H


#include <iostream>
#include <limits>
using namespace std;

class Pupil {
   protected:
    string m_name;
    int m_age;

   public:
    Pupil(const string name = "Ivan", const int age = 6);
    virtual ~Pupil();
    string getName() { return m_name; }
    int getAge() { return m_age; }
    friend ostream& operator<<(ostream& out, const Pupil& p);
    virtual ostream& print(ostream& out) const;
    
};
#endif