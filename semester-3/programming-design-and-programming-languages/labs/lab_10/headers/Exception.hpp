#ifndef SETEXCEPTION_H
#define SETEXCEPTION_H
#include <iostream>
using namespace std;
class ListException {
    int exept;

   public:
    ListException(int excpt) : exept{excpt} {};
    void Nani() {
        switch (exept) {
            case 1:
                cout << "Size error\nWe can't find this index\n";
                break;
            case 2:
                cout << "Num error\n We use positive numbers\n";
                break;
            case 3:
                cout << "Memory error" << endl;
                break;
            case 228:
                cout << "Error\nOmae Wa Mou Shindeiru\n";
                break;
        }
    }
};
// We should use it, but )
#endif