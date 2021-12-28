#include "../headers/Exception.hpp"
#include "../headers/func.hpp"
int main() {
    try {
    //notDop(); - Show before have dop
    strParce();
    }
    catch (ListException& ex) {
            system ("clear");
            ex.Nani();
    }
    return 0;
}
//TODO: DOP
// Запарсить строку с даблами интами и стрингами в три Lists
// Разбиваем её как в 7-й лабке
// for example:
// somestring with  404  a lot  9.999    of spaces and some4.55 dots 2.2   2.2
// Поиск подстроки 
// cортировка (по сути просто метод сделать)