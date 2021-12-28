
#ifndef Architectural_Object_hpp
#define Architectural_Object_hpp

#include <stdio.h>
#include <iostream>

namespace memorial {
class ArchitecturalObject {
private:
    float height;
    float square;
public:
    void SetHeight(float height);
    void SetSquare(float square);
    float GetHeight();
    float GetSquare();
    void Display();
    ArchitecturalObject();
    ArchitecturalObject(float height, float square);
    ~ArchitecturalObject();
    ArchitecturalObject(ArchitecturalObject &archObj);
};
}
#endif
