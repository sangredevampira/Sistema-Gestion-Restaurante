//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/ExtraIce.h"

ExtraIce::ExtraIce(std::shared_ptr<Product>p): ExtraBeverage(p) {
}

std::string ExtraIce::getName() {
    return "Hielo extra";
}

float ExtraIce::getPrice() {
    return 0.025;
}


std::string ExtraIce::description() {
    return baseProduct->getName() + "con hielo extra.";
}

float ExtraIce::price() {
    return baseProduct->getPrice() + 0.025;
}
