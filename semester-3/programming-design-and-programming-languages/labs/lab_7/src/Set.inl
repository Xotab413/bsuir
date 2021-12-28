#include "../headers/Set.h"

template <typename T>
Set<T>::Set() {
    m_size = 0;
    m_data = new T;
}
template <typename T>
Set<T>::Set(T data) {
    m_size = 1;
    m_data = new T [m_size];
    m_data[0] = data;
}
template <typename T>
Set<T>::~Set() {
    delete[] m_data;
}
template <typename T>
void Set<T>::add(T data) {
    bool num_eq {false};
    for (int i = 0; i < m_size; i++)
        if (m_data[i] == data)
            num_eq = true;
    if (!num_eq) {
        T* new_data = new T [++m_size];
        for (int i = 0; i < m_size; i++) 
            new_data[i] = m_data[i];
        new_data[m_size-1] = data;
        delete[] m_data;
        m_data = new_data;
    }
}
template <typename T>
T& Set<T>::operator[] (int index) {
    assert(index >=0 && index < m_size);
    return m_data[index];
}
template <typename T>
ostream& operator<< (std::ostream &out, const Set<T> &s) {
    for (int i = 0; i < s.m_size; i++) 
        out << s.m_data[i] << " ";
    return out;
}
template <typename T>
void Set<T>::erase() {
    delete [] m_data;
    m_data = nullptr;
    m_size = 0;
}
template<>
void Set<string>::add(string data) {
    bool num_eq {false};
    for (int i = 0; i < m_size; i++)
        if (m_data[i] == data)
            num_eq = true;
    if (!num_eq) {
        string* new_data = new string [m_size+1];
        for (int i = 0; i < m_size; i++) 
            new_data[i] = m_data[i];
        m_size++;
        new_data[m_size-1] = data;
        m_data->clear();
        m_data = new_data;
    }
}