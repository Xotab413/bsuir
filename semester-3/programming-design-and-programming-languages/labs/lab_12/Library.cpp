#include "Library.hpp"

int enteringANumber () {
    int num{0};
    while (true) {
        if (std::cin >> num)
            break;
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("clear");
            std::cout << "Enter THE NUM (￣□￣」): " << std::endl;
        }
    }
    return num;
}
