//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Meal.h"

Meal::Meal(std::string name, float price): Product(name, price) {
}

std::string Meal::getName() {
    return name;
}

float Meal::getPrice() {
    return price;
}
