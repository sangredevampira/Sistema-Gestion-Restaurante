//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/MediumSize.h"

MediumSize::MediumSize(std::shared_ptr<Product> p): Extras(p) {
}

std::string MediumSize::description() {
    return baseProduct->getName() + "Mediano";
}

float MediumSize::price() {
    return baseProduct->getPrice() + 0.075;
}
