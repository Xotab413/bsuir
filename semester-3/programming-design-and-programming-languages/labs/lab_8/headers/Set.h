#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;



class Set {
   public:
    int m_size;
    int* m_data;

   public:
    Set();
    Set(int data);
    Set(int* p_data, const int p_size);
    Set(const Set& source); // for copy (overloading '=' is not enough)
    ~Set();
    void add(int data);
    void erase();
    int& operator[](int index);
    friend ostream& operator<<(ostream& out, const Set& s);
    Set operator+(Set set_2); // unification  of sets U
    Set operator&(Set set_2); // intersection of sets ∩
    Set& operator=(const Set& set_src);
    friend bool operator == (const Set &s1,const Set &s2);
};
#endif

// TODO: Dop
// 1) ПОИСК ПОДМНОЖЕСТВА
// 2) Удаление дубликатов
// 3) Копирование в определённую.