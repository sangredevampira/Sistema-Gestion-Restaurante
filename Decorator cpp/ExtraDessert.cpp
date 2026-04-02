//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/ExtraDessert.h"

ExtraDessert::ExtraDessert(std::shared_ptr<Product>p): Extras(p) {
}

std::string ExtraDessert::getName() {
    return baseProduct->getName() + "con helado extra.";
}

float ExtraDessert::getPrice() {
    return baseProduct->getPrice() + 0.005;
}
