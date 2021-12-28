#include <iostream>
#include <limits>
using namespace std;



class IntArray {
private:
    int* m_array;
    int m_length;
public:
    IntArray() {
        m_length = 0;
        m_array = new int;
    }
    IntArray(const IntArray& source);
    ~IntArray() {
        delete[] m_array;
    }
    IntArray&operator=(const IntArray & source);
    int& operator[] (const int index);
    void* operator new[](size_t tip);
    void setData(int value) {}
    void push();
    void sort();
    void set_value(const int num) {m_array[0] = num;}
    friend void findSeq(IntArray* &mas, const int & size);
    friend ostream& operator<< (ostream &out, const IntArray &value);
};

// Конструктор копирования
IntArray::IntArray(const IntArray& source)
{
    // Поскольку m_length не является указателем, то мы можем выполнить поверхностное копирование
    m_length = source.m_length;
 
    // m_array является указателем, поэтому нам нужно выполнить глубокое копирование, при условии, что этот указатель не является нулевым
    if (source.m_array)
    {
        // Выделяем память для нашей копии
        m_array = new int[m_length];
 
        // Выполняем копирование
        for (int i=0; i < m_length; ++i)
            m_array[i] = source.m_array[i];
    }
    else
        m_array = 0;
}


int checkNum() {
    int num {0};
    while (true) {
        if (cin >> num) 
            break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
            system("clear");
            cout << "Enter THE NUM (￣□￣」): "<<endl;
        }
    }
    return num;
}






void findSeq(IntArray* &mas, const int & size) {

    cout <<"Enter size of your sequence: "<< endl;
    int seq_size {checkNum()}, cntr{0},is_seq{0};
    int* seq = new int [seq_size];

    cout << "Enter nums for your seqence"<<endl;

    for (int i = 0; i < seq_size; i++) {
        seq[i] = checkNum();
    }
    system("clear");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < mas[i].m_length;j++) {
            if ( seq [j] == mas[i][j] )
                cntr++;
            if (cntr == seq_size) {
                cout << "[" << i+1 << "]: " << mas[i]<<endl;
                cntr = 0;
            }
            else is_seq++; 
        }
    }

    if(is_seq == size)
        cout << "Your sequence is not here 0_0" << endl;
}





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

void printMenu() {
    cout    << "Hello User (＾▽＾)"<< endl
            << "please choose your variant"<< endl
            << "1 - add/create array"<< endl
            << "2 - add element to array" << endl
            << "3 - print all arrays"<< endl
            << "4 - sort arrays"<< endl
            // << "5 - find queue" << endl
            << "Oher num - exit"<< endl << endl;
}


void printArr(IntArray* mas, const int size) {
    system("clear");
    if (!size) {
        cout << "Create at least one array" << endl;
        return; 
    }
    cout << "Your arrray 1: " <<endl;
    for (int i = 0; i < size ; i++) 
        cout << "[" << i+1 << "]: " << mas[i]<<endl; 
    cout <<"\n";

    IntArray* arrCpy = new IntArray[size];
    for (int i = 0; i < size ; i++) {
        arrCpy[i] = IntArray(mas[i]);
    }

    

    cout << "Your arrray 2: " <<endl;
    for (int i = 0; i < size ; i++) {
        arrCpy[i].set_value(228);
        cout << "[" << i+1 << "]: " << arrCpy[i]<<endl; 
    }
    cout <<"\n";
    delete[] arrCpy;
}

void inpt(IntArray* & mas,const int & size) {
    system("clear");
    if (!size) {
        cout << "Create at least one array" << endl;
        return; 
    }
    if (size == 1) 
        mas[0].push();
    else {
        printArr(mas,size);
        cout << "Choose num of array -_-"<<endl;
        while (true) {
            int checker {checkNum()};
            if (checker > 0 && checker <= size) {
                mas[checker-1].push();
                break;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
                system("clear");
                printArr(mas,size);
                cout << "Enter the right num (´• ω •): "<<endl;
            }
        }
    }
}


void sortArr(IntArray* & mas,const int & size) {
    system("clear");
    if (!size) {
        cout << "Create at least one array" << endl;
        return; 
    }
    for (int i = 0; i < size; i++) {
        mas[i].sort();
    }
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
void add(IntArray* & mas,int & size) {
    if (!size) {
        mas = new IntArray [1];
        ++size;
    }
    else {
        IntArray* temp = new IntArray [++size];
        for (int i = 0; i < size - 1; i++) {
            temp[i] = mas[i];
        }
        delete[] mas;
        mas = new IntArray [size];
        for (int i = 0; i < size; i++) {
            mas[i] = temp[i];
        }
        delete[] temp;
    }
}
void mainMenu() {
    IntArray* arr;
    int size_arr{0};
    printMenu();
    while(1) {
        int chooser {checkNum()};
        switch (chooser) {
        case 1:
            add (arr,size_arr);
            system("clear");
            printMenu();
            break;
        case 2: 
            inpt(arr,size_arr);
            printMenu();
            break;
        case 3:
            printArr(arr,size_arr);
            printMenu();
            break;
        case 4:
            sortArr(arr,size_arr);
            printMenu();
            break;    
        case 5: 
            // findSeq(arr,size_arr);
            // printMenu();
            break;
        default:
            return;
        }
    }
    delete[] arr;
}

int main () {
    
    mainMenu();
    return 0;
}