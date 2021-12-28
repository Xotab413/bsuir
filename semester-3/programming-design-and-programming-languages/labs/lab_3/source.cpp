#include <iostream>
#include <math.h>
#include <limits>
using namespace std;
class Int {
    int m_value;
public :

    ///friend function
    friend Int operator+(const Int& f_num, const Int& s_num);
    friend Int operator+(const Int& f_num, int s_num);
    friend Int operator+(int f_num, const Int& s_num);
    friend ostream& operator<< (ostream &out, const Int &value);
    friend istream& operator>> (istream &in, Int &value);
    friend bool operator<(const Int &f_num, const Int &s_num);
    friend bool operator<(const Int &f_num, int s_num);
    friend bool operator<(int f_num, const Int &s_num);
    friend Int& operator--(Int& num); // prefix
    friend Int operator--(Int& num,int); // postfix
    //<
    /////method
    Int operator-(const Int &value);
    bool operator>(const Int &f_num);
    Int& operator++(); // prefix
    Int operator++(int); // postfix
    void operator[](const int num);
    Int& operator()(const int power);
    operator int() { return m_value;}


    //>
    /////
    Int(const int value = 0) :
        m_value{value}
        {    
        }
    int getValue()   { return m_value;}
    void setValue(int value) { m_value = value;}




};

/////////// via friend fun 
Int operator+(const Int &f_num, const Int &s_num) {
    return Int (f_num.m_value + s_num.m_value);
}
Int operator+(int f_num, const Int& s_num) {
    return Int(f_num + s_num.m_value);
}
Int operator+(const Int& f_num, int s_num) {
    return Int(s_num + f_num.m_value);
}
ostream& operator<< (ostream &out, const Int &value) {
    out << value.m_value;
    return out;
}
istream& operator>> (istream &in, Int &value){
    cout << "Enter a positive number" << endl;
    while (true) {
        if (cin >> value.m_value && value.m_value >= 0) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
            system("clear");
            cout << "Error input, try again: ";
        }
    }
    system("clear");
    return in;
}
bool operator<(const Int &f_num, const Int &s_num) {
    return (f_num.m_value < s_num.m_value);
}
bool operator<(const Int &f_num, int s_num) {
    return (f_num.m_value < s_num);
}
bool operator<(int f_num, const Int &s_num) {
    return !(s_num < f_num);
}
Int& operator--(Int& num) { // prefix version
    --num.m_value;
    return num;
}
Int operator--(Int& num,int) { // postfix version
    Int temp(num.m_value);
    --num;
    return temp;
}


////////// via method of function
Int Int::operator-(const Int &num) {
    return Int(m_value - num.m_value);
}
bool  Int::operator>(const Int &num) {
    return (m_value > num.m_value);
}
Int& Int::operator++() { // prefix version
    ++m_value;
    return *this;
}
Int Int::operator++(int) { // postfix version
    Int temp(m_value);
    ++(*this);
    return temp;
}
void Int::operator[](const int num) {
    system("clear");
    cout <<"Simple number - " <<  num << endl;
}
Int& Int::operator()(const int power) {
    m_value = pow(m_value,power);
    return *this;
}

/////// just fun
int checkChooser() {
    int chooser {0};
    while (true) {
        if (cin >> chooser) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
            system("clear");
            cout << "Enter the valid input: ";
        }
    }
    return chooser;
}
void printMenu() {
    cout    << "Hello User (＾▽＾)"<< endl
            << "please choose your function overloading option"<< endl
            << "1 - ++/--"<< endl
            << "2 - []"<< endl
            << "3 - ()"<< endl
            << "4 - < / >"<< endl
            << "5 - +/-"<< endl
            << "Oher num - exit"<< endl << endl;
}
string trFalse (const bool &some) {
    if (some)
        return ("true");
    else return ("false");
}
void incDecr() {
    Int num;
    cin >> num;
    Int a {num};
    Int b {num};
    cout << "Current number: " << num << endl
         << "c = a++ + ++b: " << a++ + ++b << endl
         << "a = " << a << endl
         << "b = " << b << endl
         << "Increment: " << endl
         << "postfix (a++) - " << num++ << endl
         << "prefix (++a) - " << ++num << endl
         << "Decrement: " << endl
         << "postfix (a--) - " << num-- << endl
         << "prefix (--a) - " << --num << endl;
}
void indexing() {
    Int num;
    cout << "This override represent output differnet num via indexing" << endl
         << "please enter a number" << endl;
    num[checkChooser()];
}
void initializing() {
    Int num;
    cin >> num;
    cout << "Enter a power" << endl;
    int pwr {checkChooser()};
    system("clear");
    cout << "Current num: " << num << endl
         << "raised num: " << int(num(pwr)) << endl;
}
void moreLess() {
    Int f_num, s_num{444};
    int th_num{300};
    cin >> f_num;
    cout << "Via method: " << endl
         << f_num << " > " << s_num << " : " << trFalse(f_num > s_num) << endl
         << "Via friend functions: " << endl
         << f_num << " < " << s_num << " : " << trFalse(f_num < s_num) << endl
         << f_num << " < " << th_num << " : " << trFalse(f_num < th_num) << endl
         << th_num << " < " << s_num << " : " << trFalse(th_num < s_num) << endl;
}
void sumDifference() {
    Int f_num, s_num{444};
    int th_num{300};
    cin >> f_num;
    cout << "Via method: " << endl
         << f_num << " - " << s_num << " = " << (f_num - s_num) << endl
         << "Via friend functions: " << endl
         << f_num << " + " << s_num << " = " << (f_num + s_num) << endl
         << f_num << " + " << th_num << " = " << (f_num + th_num) << endl
         << th_num << " + " << s_num << " = " << (th_num + s_num) << endl;
}
void mainMenu() {
    printMenu();
    while(1) {
        int chooser {checkChooser()};
        switch (chooser) {
        case 1:
            system("clear");
            incDecr();
            printMenu();
            break;
        case 2:
            system("clear");
            indexing();
            printMenu();
            break;
        case 3:
            system("clear");
            initializing();
            printMenu();
            break;  
        case 4:
            system("clear");
            moreLess();
            printMenu();
            break;
        case 5:
            system("clear");
            sumDifference();
            printMenu();
            break;  
        default:
            return;
        }
    }
}


int main() {
    mainMenu();
    return 0;
}