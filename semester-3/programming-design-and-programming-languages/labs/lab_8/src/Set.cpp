#include "../headers/Set.h"


Set::Set() {
    m_size = 0;
    m_data = new int;
}
Set::Set(int data) {
    m_size = 1;
    m_data = new int [m_size];
    m_data[0] = data;
}
Set::Set(int p_data[],const int p_data_size) {
    m_size = p_data_size;
    m_data = new int [m_size];
    for (int i = 0; i < m_size; i++)
        m_data[i] = p_data[i];
}
Set::Set(const Set& sourse) {
    m_size = sourse.m_size;
    if (sourse.m_size) {
        m_data = new int [m_size];
        for (int i = 0; i < m_size; i++)
            m_data[i] = sourse.m_data[i];
    }
    else 
        m_data = 0;
}
Set& Set::operator=(const Set& set_src) {
    if (this == &set_src)
        return *this;
    delete[] m_data;
    m_size = set_src.m_size;
    if (set_src.m_data) {
        m_data = new int [m_size];
        for (int i = 0; i < m_size; i++)
            m_data[i] = set_src.m_data[i];
    }
    else 
        m_data = 0;
    return *this;
}
Set::~Set() {}

//--------------------------------------------------
void Set::add(int data) {
    bool num_eq {false};
    for (int i = 0; i < m_size; i++)
        if (m_data[i] == data)
            num_eq = true;
    if (!num_eq) {
        int* new_data = new int [++m_size];
        for (int i = 0; i < m_size; i++) 
            new_data[i] = m_data[i];
        new_data[m_size-1] = data;
        delete[] m_data;
        m_data = new_data;
    }
}
int& Set::operator[] (int index) {
    // assert(index >=0 && index < m_size); // try catch
    return m_data[index];
}
ostream& operator<< (std::ostream &out, const Set &s) {
    for (int i = 0; i < s.m_size; i++) 
        out << s.m_data[i] << " ";
    return out;
}
bool operator==(const Set& s1, const Set& s2) {
    int cnt {0};
    for (int i = 0; i < s1.m_size; i++) 
        if (s1.m_data[i] == s2.m_data[i])
            cnt ++;
    return cnt == s1.m_size ? true : false;
}
void Set::erase() {
    delete [] m_data;
    m_data = nullptr;
    m_size = 0;
}
Set Set::operator+(Set set_2) {
    Set result;
    for (int i = 0; i < this->m_size;i++)
        result.add(this->m_data[i]);
    for (int i = 0; i < set_2.m_size;i++)
        result.add(set_2.m_data[i]);
    return result;
}
Set Set::operator&(Set set_2) {
    Set result;
    for (int i = 0; i < this->m_size; i++)
        for (int j = 0; j < set_2.m_size; j++)
            if (this->m_data[i] == set_2.m_data[j])
                result.add(set_2.m_data[j]);
    return result;
}
//--------------------------------------------------