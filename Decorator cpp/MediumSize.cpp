//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/MediumSize.h"

MediumSize::MediumSize(std::shared_ptr<Product> p): Extras(p) {
}

std::string MediumSize::getName() {
    return "Mediano";
}

float MediumSize::getPrice() {
    return 0.075;
}

std::string MediumSize::description() {
    return baseProduct->getName() + "mediano";
}

float MediumSize::price() {
    return baseProduct->getPrice() + 0.075;
}
