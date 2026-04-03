//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/MealExtra.h"

MealExtra::MealExtra(std::string name, float price)
    : Extras(name, price) {
}

std::string MealExtra::getName() {
    return name;
}

float MealExtra::getPrice() {
    return price;
}
