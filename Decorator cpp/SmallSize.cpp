//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/SmallSize.h"

SmallSize::SmallSize(std::shared_ptr<Product>p): Extras(p){
}

std::string SmallSize::getName() {
    return "Pequeno";
}

float SmallSize::getPrice() {
    return 0.050;
}

std::string SmallSize::description() {
    return baseProduct->getName() + "pequeno";
}

float SmallSize::price() {
    return baseProduct->getPrice() + 0.050;
}
