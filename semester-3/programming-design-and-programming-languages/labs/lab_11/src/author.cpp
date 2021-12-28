#include "author.h"

namespace memorial {

std::string Author:: GetName() {
    return name;
}

std::string Author:: GetSurname() {
    return surname;
}

void Author:: SetName(std::string name) {
    this -> name = name;
}

void Author:: SetSurName(std::string surname) {
    this -> surname = surname;
}

Author:: ~Author() {
}

Author:: Author () {
    SetName("");
    SetSurName("");
}

Author:: Author(std::string name, std::string surname) {
    SetName(name);
    SetSurName(surname);
}

void Author::Display() {
    
    std::cout << std::endl << "Author name class: " << name << std::endl;
    std::cout << std::endl << "Author surname class: " << surname << std::endl;
}

Author:: Author(Author &authorObj) {
    this -> name = authorObj.name;
    this -> surname = authorObj.surname;
}
}
