#ifndef UserClass_hpp
#define UserClass_hpp


#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <fstream>
#include "Library.hpp"
using namespace std;
class UserClass {
private:
    std::map<char, int> data;
public:
    UserClass();
    void Operation();
    void Display();
    void Setdata(char key , int Data);
    void WriteInFile();
    void AddInformation();
    void MathOperation();
};

#endif /* UserClass_hpp */
