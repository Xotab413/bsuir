#include "Material.h"

namespace memorial {
void Material:: SetPrice(int price) {
    this -> price = price;
}

void Material:: SetNameOfMaterial(std::string nameOfMaterial) {
    this -> nameOfMaterial = nameOfMaterial;
}

int Material:: GetPrice() {
    return price;
}

std::string Material:: GetNameOfMaterial() {
    return nameOfMaterial;
}

void Material:: Display() {
    std::cout << "Material class name of material: " << nameOfMaterial << std::endl;
    std::cout << "Material class price: " << price << std::endl;
}

Material:: Material () {
    SetPrice(0);
    SetNameOfMaterial("");
}

Material:: Material(std::string nameOfMaterial, int price) {
    SetPrice(price);
    SetNameOfMaterial(nameOfMaterial);
}

Material:: ~Material () {
}

Material::Material (Material &matObj) {
    this -> nameOfMaterial = matObj.nameOfMaterial;
    this -> price = matObj.price;
}
}
