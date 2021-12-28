#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
#include <limits>
using namespace std;
class IntArray {
private:
    int* m_array;
    int m_length;
public:
    IntArray&operator=(const IntArray & source);
    IntArray() {
        m_length = 0;
        m_array = new int;
    }
    ~IntArray() {
        delete[] m_array;
    }
    int& operator[] (const int index);
    void* operator new[](size_t tip);
    void push();
    void sort();
    friend void findSeq(IntArray* &mas, const int & size);
    friend ostream& operator<< (ostream &out, const IntArray &value);
};
#endif