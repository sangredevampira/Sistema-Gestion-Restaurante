//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/ExtraFries.h"

ExtraFries::ExtraFries(Product *baseProduct)
    : ExtraFood(baseProduct) {
}

std::string ExtraFries::description() {
    return baseProduct->getName() + " con papas extra";
}

float ExtraFries::price() {
    return baseProduct->getPrice() + 0.5;
}