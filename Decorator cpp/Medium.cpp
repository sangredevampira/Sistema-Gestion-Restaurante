//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Medium.h"

Medium::Medium(Product *baseProduct): Extras(baseProduct) {
}

std::string Medium::description() {
    return baseProduct->getName() + "Mediano";
}

float Medium::price() {
    return 0.75 + baseProduct->getPrice();
}
