#include <iostream>
using namespace std;
void println(const char* str ) {
    for (int i = 0; str[i] != '\0';i++)
        cout << str[i];
}
int lastindx (const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++){}
    return i-1;
}
char* reverse(char* str) {
    for(int i = 0,j = lastindx(str); i < j; i++,j--)
        swap(str[i],str[j]);
    return str;
}
int find_num(const char* str) {
    int sum = 0;
    for(int i = 0; str[i]!='\0';i++) {
        if(str[i] >= '0' && str[i] <= '9')
            sum+= str[i] - '0';
    }
    return sum;
}
char* del_num(const char* str) {
    char* buf = new char(80);
    int j = 0;
    for(int i = 0; str[i]!='\0';i++) {
        if(!(str[i] >= '0' && str[i] <= '9'))
            buf[j++] = str[i];
    }
    return buf;
}
int main() {
    char* str = new char(80);
    cout << "Please enter a string" << endl;
    cin.getline(str,80);
    println(reverse(del_num(str)));
    cout << find_num(str);
    delete[] str;
    return 0;
}