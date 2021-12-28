#include "../headers/List.hpp"
#include "../headers/Iterator.hpp"

template <typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
void List<T>::pop_front() {
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template <typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    } else {
        Node<T> *current = this->head;

        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    Size++;
}

template <typename T>
void List<T>::clear() {
    while (Size) {
        pop_front();
    }
}

template <typename T>
T &List<T>::operator[](const int index) {
    int counter = 0;
    if (index < 0) throw(1);
    Node<T> *current = this->head;

    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template <typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data, head);
    Size++;
}

template <typename T>
void List<T>::insert(T data, int index) {
    if (index == 0) {
        push_front(data);
    } else {
        Node<T> *previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node<T> *newNode = new Node<T>(data, previous->pNext);

        previous->pNext = newNode;
        Size++;
    }
}

template <typename T>
void List<T>::removeAt(int index) {
    if (index == 0) {
        pop_front();
    } else {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node<T> *toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        Size--;
    }
}

template <typename T>
void List<T>::pop_back() {
    removeAt(Size - 1);
}

template <class T>
void List<T>::sortAcrossContent() {
    int choice;
    std::cout << "Enter type sort " << std::endl;
    std::cout << "1 - по уменьшению" << std::endl;
    std::cout << "2 - по увеличению" << std::endl;

    Node<T> *cur1 = head;
    Node<T> *cur2 = head;
    std::cin >> choice;
    switch (choice) {
        case 2:

            for (int i = 0; i < Size; i++) {
                for (int j = 0; j < Size - 1; j++) {
                    if (cur1->data < cur2->data) {
                        T temp = cur1->data;
                        cur1->data = cur2->data;
                        cur2->data = temp;
                    }
                    cur2 = cur2->pNext;
                }
                cur2 = head;
                cur1 = head->pNext;
                for (int k = 0; k < i; k++) {
                    cur1 = cur1->pNext;
                }
            }
            break;
        case 1:

            for (int i = 0; i < Size; i++) {
                for (int j = 0; j < Size - 1; j++) {
                    if (cur1->data > cur2->data) {
                        T temp = cur1->data;
                        cur1->data = cur2->data;
                        cur2->data = temp;
                    }
                    cur2 = cur2->pNext;
                }
                cur2 = head;
                cur1 = head->pNext;
                for (int k = 0; k < i; k++) {
                    cur1 = cur1->pNext;
                }
            }
            break;
        default:
            break;
    }
}

template <typename T>
ostream& operator<< (std::ostream &out,  List<T> &list) {
    for (auto& l : list) 
        out << l << " ";
    return out;
}

//Iter method
template<typename T> typename List<T>::Iterator List<T>::Insert(List<T>::Iterator position, const T &value) {
    Node<T>* newNode = new Node<T>(value, position.nodePtr->next);
    if (position.nodePtr == head + GetSize()) head + GetSize() = newNode;
    position.nodePtr->next = newNode;
    return position;
}
template<typename T> typename List<T>::Iterator List<T>::erase(List<T>::Iterator position) {
    Node<T>* toDelete = position.nodePtr->next;
    position.nodePtr->next = position.nodePtr->next->next;
    if (toDelete == head + GetSize()) head + GetSize() = position.nodePtr;
    delete toDelete;
    return position;
}