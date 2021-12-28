#ifndef PUPIL_H
#define PUPIL_H

#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
class Pupil {
   protected:
    string m_name;
    int m_age;

   public:
    Pupil(const string name = "Ivan", const int age = 6);
    string getName() { return m_name; }
    int getAge() { return m_age; }
    void setName(string name) { m_name = name; }
    void setAge(int age) { m_age = age; }
    friend ostream& operator<<(ostream& out, const Pupil* p);
    virtual ostream& print(ostream& out) const = 0;
    virtual string type() = 0;
    virtual string getWorkpl() = 0;
    virtual int getGrade() = 0;
    virtual int getCourse() = 0;
    virtual ~Pupil();
};
#endif

// TODO: Dop 
/// 1) поиск диапазона от до 
/// 2) удaление дубликатов отд функция