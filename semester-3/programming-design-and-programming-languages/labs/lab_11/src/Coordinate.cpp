#include "Coordinate.h"

namespace memorial {
void Coordinate:: SetLatitude(float latitude) {
    this -> latitude = latitude;
}

void Coordinate:: SetLongitude(float longitude) {
    this -> longitude = longitude;
}

void Coordinate:: Display() {
    std::cout << "Coordinate latitude class: " << latitude << std::endl;
    std::cout << "Coordinate longitude class: " << longitude << std::endl;
}

float Coordinate:: GetLatitude() {
    return latitude;
}

float Coordinate:: GetLongitude() {
    return longitude;
}

Coordinate:: Coordinate() {
    this -> longitude = 0.0;
    this -> latitude = 0.0;
}

Coordinate:: Coordinate(float latitude, float longitude) {
    this -> latitude = latitude;
    this -> longitude = longitude;
}

Coordinate:: ~Coordinate () {
}

Coordinate:: Coordinate(Coordinate &coorMat) {
    this -> longitude = coorMat.longitude;
    this -> latitude = coorMat.latitude;
}

}
