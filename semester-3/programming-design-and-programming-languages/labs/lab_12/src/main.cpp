#include "UserClass.hpp"
#include <fstream>
int main(int argc, const char * argv[]) {
    system("clear");
    std::ifstream sourceFile;
    std::map<char, int>mapTemp;
    std::string fileString;
    UserClass data;
    
   try {
       std::cout << "BLOCK TRY" << std::endl;
       sourceFile.open("../sourceFile.txt");
       std::cout << "Файл sourceFile.txt открыт" << std::endl;
   } catch (std::exception &ex) {
       std::cout << "BLOCK CATCH" << std::endl;
       ex.what();
   }

   std::cout << std::endl << std::endl << "Считываем информацию с файла в std::map " <<std::endl;
   char c = '\0';
   while (true) {
       char key;
       c = sourceFile.get();
       if (sourceFile.eof()) {
           break;
       }
       if (c >= 'a' && c <= 'z') {
           key = c;
       }
       if (c >= '0' && c <= '9') {
           mapTemp.emplace(key, c - '0');
       }
   }
   std::cout << "Переносим ключ и значение в класс, где эти параметры записываются в другой std::map" << std::endl;
   for (auto it = mapTemp.begin(); it != mapTemp.end(); it++) {

       data.Setdata(it->first, it->second);
   }

   std::cout << std::endl << std::endl << "Вывод std::map класса userClass" << std::endl;
   data.Display();
   std::cout << std::endl << std::endl << "Проводятся математические операции над значениями std::map в userClass" << std::endl;
//    data.Operation(); - use it not for dop
   data.MathOperation();
   std::cout << "Вывод std::map класса userClass после математических операций" << std::endl << std::endl <<  std::endl;
   data.Display();
   std::cout << std::endl << std::endl << "Запись std::map в UserClass в resultFile.txt" << std::endl;
   data.WriteInFile();
   std::cout << "Закрытие файла sourceFile.txt" << std::endl;
   sourceFile.close();
    return 0;
}
