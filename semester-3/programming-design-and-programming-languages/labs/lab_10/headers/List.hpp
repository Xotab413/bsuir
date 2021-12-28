#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <string>
using namespace std;

template <class T>
class List;
template <class T>
ostream& operator<<(ostream&, List<T>& list);
// why we use this, read in lab_7

template <typename T>
class Node {
   public:
    Node* pNext;
    T data;

    Node(T data = T(), Node* pNext = nullptr) {
        this->data = data;
        this->pNext = pNext;
    }
};
template <typename T>
class List {
   public:
    List();
    ~List();
    void pop_front();
    void push_back(T data);
    void clear();
    int GetSize() { return Size; }
    T& operator[](const int index);
    void push_front(T data);
    void insert(T data, int index);
    void removeAt(int index);
    void pop_back();
    void sortAcrossContent();
    friend ostream& operator<<<>(ostream& out, List<T>& list);
    class Iterator;
    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
    Iterator Insert(Iterator position, const T& value);
    Iterator erase(Iterator position);

   private:
    int Size;
    Node<T>* head;
};
#include "../src/List.inl"
#endif