#ifndef SET_H
#define SET_H

#include <assert.h>

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Set;
template <class T>
ostream& operator<<(ostream&, const Set<T>& s);

/* NOTE: Why we should use like this ? -_-
Because operator<< is really a template function,
you need to supply a template declaration for prior to the declaration of
template class Set. However, because operator<< has a parameter of type Set<T>
you must precede the function declaration with a declaration of Set<T>.
*/

template <class T>
class Set {
   public:
    int m_size;
    T* m_data;

   public:
    Set();
    Set(T data);
    ~Set();
    void add(T data);
    void erase();
    T& operator[](int index);
    friend ostream& operator<<<>(ostream& out, const Set<T>& s);
};
#include "../src/Set.inl"
#endif

// TODO: Dop
// Запарсить строку с даблами интами и стрингами в три множества
// for example:
// somestring with  404  a lot  9.999    of spaces and some4.55 dots 4.   .2