#include "Architectural Object.h"

namespace memorial {

void ArchitecturalObject:: SetHeight(float height) {
    this -> height = height;
}

void ArchitecturalObject:: SetSquare(float square) {
    this -> square = square;
}

float ArchitecturalObject:: GetHeight() {
    return height;
}

float ArchitecturalObject:: GetSquare() {
    return square;
}

void ArchitecturalObject:: Display() {
    std::cout << std::endl << "ArchitecturalObject class height: " << height << std::endl;
    std::cout << std::endl << "ArchitecturalObject class square: " << square << std::endl;
}

ArchitecturalObject::ArchitecturalObject () {
    SetSquare(0.0);
    SetHeight(0.0);
}

ArchitecturalObject:: ArchitecturalObject(float height, float square) {
    SetSquare(square);
    SetHeight(height);
}

ArchitecturalObject:: ~ArchitecturalObject () {
}

ArchitecturalObject::ArchitecturalObject(ArchitecturalObject &archObj) {
    this -> height = archObj.height;
    this -> square = archObj.square;
}

}
