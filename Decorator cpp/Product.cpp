//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Product.h"

Product::Product(std::string name, float price) {
    this->name = name;
    this->price = price;
}
std::ostream & operator<<(std::ostream &os, const Product *baseProduct) {
    os << "Nombre: "<< baseProduct->name << std::endl;
    os << "Precio: " << baseProduct->price << std::endl;
    return os;
}