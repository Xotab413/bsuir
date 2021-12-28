#include "UserClass.hpp"

void UserClass:: Display() {
    std::cout << "UserClass data:" << std::endl;
    
    for (auto it = data.begin(); it != data.end(); ++it) {
        std::cout << "Key: " << it -> first << " Data: " << it -> second << std::endl;
    }
}

UserClass::UserClass() {
    
}

void UserClass::Setdata(char key, int Data) {
    std::cout << "Устанавливаем данные в std::map в UserClass" << std::endl;

    this -> data[key] = Data;
}

void UserClass::Operation() {
    std::cout << "Выполняются математические операции" << std::endl;
    int i = 0;
    for (auto it = data.begin(); it != data.end(); ++it, i++) {
        it -> second += i * 5;
        it -> second += 12;
        it -> second --;
    }
}

void UserClass::WriteInFile() {
    std::ofstream on;
    
    try {
        std::cout << "BLOCK TRY" << std::endl;
        on.open("../resultFile.txt");
        std::cout << "Файл resultFile.txt открыт" << std::endl;
    } catch (std::exception &ex) {
        std::cout << "BLOCK CATCH" << std::endl;
        ex.what();
    }
    
    for (auto it = data.begin(); it != data.end(); ++it) {
        on << it -> first << '=' << it -> second << '\n';
    }
    on.close();
    
}

void UserClass::AddInformation() {
    std::cout << "enter key" << std::endl;
    char key;
    std::cin >> key;
    std::cout << "Enter number" << std::endl;
    int number = enteringANumber();
    data.emplace(key,number);
    std::cout << std::endl << std::endl;
}

void UserClass:: MathOperation() {
    for (auto it = data.begin(); it != data.end(); ++it) {
        std::cout << "Enter number" << std::endl;
        std::cout << "1 -   +" << std::endl;
        std::cout << "2 -   -" << std::endl;
        std::cout << "3 -   *" << std::endl;
        std::cout << "4 -   /" << std::endl;
        int mathOperation = enteringANumber();
        if (mathOperation == 1) {
            std::cout << "Enter number" << std::endl;
            int number = enteringANumber();
            it -> second += number;
        }
        if (mathOperation == 2) {
            std::cout << "Enter number" << std::endl;
            int number = enteringANumber();
            it -> second -= number;
        }
        if (mathOperation == 3) {
            std::cout << "Enter number" << std::endl;
            int number = enteringANumber();
            it -> second *= number;
        }
        if (mathOperation == 4) {
            std::cout << "Enter number" << std::endl;
            int number = enteringANumber();
            it -> second /= number;
        }
        
        std::cout << std::endl << std::endl;
    }
}
