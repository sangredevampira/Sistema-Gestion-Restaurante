//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/ExtraIceCream.h"

ExtraIceCream::ExtraIceCream(std::shared_ptr<Product>p): ExtraDessert(p) {
}

std::string ExtraIceCream::description() {
    return baseProduct->getName() + " con extra helado";
}

float ExtraIceCream::price() {
    return baseProduct->getPrice() + 0.05;
}
