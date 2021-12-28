#ifndef author_hpp
#define author_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
namespace memorial {
class Author {
private:
    std::string name;
    std::string surname;
public:
    void SetName(std::string name);
    void SetSurName(std::string surname);
    std::string GetName();
    std::string GetSurname();
    void Display();
    Author();
    Author(std::string name, std::string surname);
    ~Author();
    Author(Author &authorObj);
};
}

#endif /* author_hpp */
