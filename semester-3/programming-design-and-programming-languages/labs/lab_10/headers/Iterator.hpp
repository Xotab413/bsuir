#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "./List.hpp"

template <class T>
class List<T>::Iterator {
    friend class List;

   private:
    Node<T>* nodePtr;
    // The constructor is private, so only our friends
    // can create instances of Iterators.
    Iterator(Node<T>* newPtr) : nodePtr(newPtr) {}

   public:
    Iterator() : nodePtr(nullptr) {}

    // Overload for the comparison operator !=
    bool operator!=(const Iterator& itr) const {
        return nodePtr != itr.nodePtr;
    }

    // Overload for the dereference operator *
    T& operator*() const { return nodePtr->data; }

    // Overload for the preincrement operator ++
    Iterator operator++() {
        nodePtr = nodePtr->pNext;
        return nodePtr;
    }

    // Overload for the postincrement operator ++
    Iterator operator++(int) {
        Iterator temp = *this;
        nodePtr = nodePtr->pNext;
        return temp;
    }
};

#endif
