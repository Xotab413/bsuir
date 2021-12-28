
#ifndef Material_hpp
#define Material_hpp

#include <stdio.h>
#include <iostream>

namespace memorial {
class Material {
private:
    std::string nameOfMaterial;
    int price;
public:
    void SetNameOfMaterial(std::string nameOfMaterial);
    void SetPrice(int price);
    std::string GetNameOfMaterial();
    int GetPrice();
    void Display();
    Material();
    Material(std::string nameOfMaterial, int price);
    ~Material();
    Material(Material &marObj);
};
}

#endif 
