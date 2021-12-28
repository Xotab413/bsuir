#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H
#include <iostream>
using namespace std;
class FileException {
    int exept;

   public:
    FileException(int excpt) : exept{excpt} {};
    void Nani() {
        switch (exept) {
            case 1:
                cout << "Error open file\n";
                break;
            case 2:
                cout << "False input\n";
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
#endif