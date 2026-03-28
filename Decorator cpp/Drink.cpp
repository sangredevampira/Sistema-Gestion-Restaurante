//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Drink.h"

Drink::Drink(std::string name, float price):Product(name, price) {
}

std::string Drink::getName() {
    return name;
}

float Drink::getPrice() {
    return price;
}
