#include "Description.h"

namespace memorial {
void Description::SetOpeningDate(std::string openingDate) {
    this -> openingDate = openingDate;
}

void Description::SetExpendedResources(int expendedResource) {
    this -> expendedResources = expendedResource;
}

std::string Description:: GetOpeningDate() {
    return openingDate;
}

int Description:: GetExpendedResources() {
    return expendedResources;
}

Description:: Description () {
    this -> openingDate = "0.00.0000";
    this -> expendedResources = 0;
}

Description:: Description(std::string openingDate, int expendedResources) {
    SetOpeningDate(openingDate);
    SetExpendedResources(expendedResources);
}

Description:: ~Description () {
}

void Description:: Display() {
    std::cout << std::endl << "Description opening date: " << openingDate << std::endl;
    std::cout << std::endl << "Description expendedResources: " << expendedResources << std::endl;

}

Description:: Description(Description &descObj) {
    this -> openingDate = descObj.openingDate;
    this -> expendedResources = descObj.expendedResources;
}

}
