#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Plant {
    double m_lenght;
    string m_name;
    int m_age;

   public:
    Plant() {
        m_lenght = 0.0;
        m_name = "";
        m_age = 0;
    }
    Plant(double, string, int);
    Plant(Plant const &plant);
    string getName() { return m_name; }
    double getLenght() { return m_lenght;}
    int getAge() {return m_age; }
    void setName(const string name) {m_name = name;}
    void setLenght(const double lenght) {m_lenght = lenght;}
    void setAge(const int age) {m_age = age;}
    friend ostream& operator<<(ostream& os, const Plant& plant);
    friend istream& operator>>(istream& is, Plant& plant);
    void textMode(const string);
    void binaryMode(const  string);
    friend bool operator == (const Plant &pl1,const Plant &pl2);
};

#endif