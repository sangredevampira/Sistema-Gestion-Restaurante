//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/ExtraIceCream.h"

ExtraIceCream::ExtraIceCream(std::shared_ptr<Product>p): ExtraDessert(p) {
}

std::string ExtraIceCream::getName() {
    return "Extra helado";
}

float ExtraIceCream::getPrice() {
    return 0.05;
}

std::string ExtraIceCream::description() {
    return baseProduct->getName() + "con helado extra.";
}

float ExtraIceCream::price() {
    return baseProduct->getPrice() + 0.05;
}
