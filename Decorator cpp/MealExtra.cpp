//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/MealExtra.h"

MealExtra::MealExtra(std::shared_ptr<Product> p): Extras(p)  {
}

std::string MealExtra::getName() {
    return baseProduct->getName() + " con papas Fritas";
}

float MealExtra::getPrice() {
    return baseProduct->getPrice() + 550;
}
