#include <IntArray.h>
#include <fun.h>





// Оператор присваивания
IntArray& IntArray::operator=(const IntArray & source) {
    
    if (this == &source)// Проверка на самоприсваивание
        return *this;
    delete[] m_array;// Сначала нам нужно очистить предыдущее значение m_array (члена неявного объекта)
    m_length = source.m_length;// Поскольку m_length не является указателем, то мы можем выполнить поверхностное копирование
    // m_array является указателем, поэтому нам нужно выполнить глубокое копирование, при условии, что этот указатель не является нулевым
    if (source.m_array) {
        m_array = new int[m_length];// Выделяем память для нашей копии
        for (int i=0; i < m_length; ++i)// Выполняем копирование
            m_array[i] = source.m_array[i];
    }
    else
        m_array = 0;
    return *this;
}
void IntArray::sort() {
    for(size_t i = 0; i < m_length; ++i) 
        for (size_t j = i+1; j < m_length; ++j) 
            if (m_array[i] > m_array[j])
                swap(m_array[i], m_array[j]);
}
int& IntArray::operator[] (const int index) {
    return m_array[index];
}
ostream& operator<< (ostream &out, const IntArray &value) {
    for (int i = 0; i < value.m_length; i++)
        out << value.m_array[i] << " ";
    return out;
}
void* IntArray::operator new[](size_t tip) {
		IntArray* cpy = (IntArray*)malloc(tip);
		return cpy;
}
void IntArray::push() {
    if (!m_length) {
        m_array = new int(checkNum());
        m_length++;
    }
    else {
        int* temp = new int [++m_length];
        for (int i = 0; i < m_length - 1; i++) {
            temp[i] = m_array[i];
        }
        temp[m_length-1] = checkNum();
        delete[] m_array;
        m_array = new int [m_length];
        for (int i = 0; i < m_length; i++) {
            m_array[i] = temp[i];
        }
        delete[] temp;
    }
}
