
#ifndef Coordinate_hpp
#define Coordinate_hpp

#include <iostream>
#include <stdio.h>

namespace memorial {
class Coordinate {
private:
    float latitude;
    float longitude;
public:
    void SetLatitude(float latitude);
    void SetLongitude(float longitude);
    float GetLatitude();
    float GetLongitude();
    void Display();
    Coordinate();
    Coordinate(float latitude, float longitude);
    ~Coordinate();
    Coordinate(Coordinate &coorObj);
};
}

#endif /* Coordinate_hpp */
