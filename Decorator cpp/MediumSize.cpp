//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/MediumSize.h"

MediumSize::MediumSize(std::shared_ptr<Product> p,std::string name, float price): Extras(p, name, price) {
}

std::string MediumSize::getName() {
    return baseProduct->getName() + " tamaño mediano/a. ";
}

float MediumSize::getPrice() {
    return baseProduct->getPrice() + 0.075;
}
