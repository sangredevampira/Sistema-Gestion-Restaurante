//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/MealExtra.h"

MealExtra::MealExtra(std::shared_ptr<Product> p, std::string name, float price)
    : Extras(p, name, price) {
}

std::string MealExtra::getName() {
    return baseProduct->getName() + " " + name;
}

float MealExtra::getPrice() {
    return price;
}
