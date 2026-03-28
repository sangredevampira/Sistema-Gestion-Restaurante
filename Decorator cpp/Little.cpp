//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Little.h"

Little::Little(Product *baseProduct): Extras(baseProduct) {
}

std::string Little::description() {
    return baseProduct->getName() + "Pequeno";
}

float Little::price() {
    return 0.50 + baseProduct->getPrice();
}
