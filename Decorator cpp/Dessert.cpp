//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Dessert.h"

Dessert::Dessert(std::string name, float price): Product(name, price) {
}

std::string Dessert::getName() {
    return name;
}

float Dessert::getPrice() {
    return price;
}
