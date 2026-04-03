//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/ExtraDessert.h"

ExtraDessert::ExtraDessert(std::shared_ptr<Product> p, std::string name, float price): Extras(p, name, price) {
}

std::string ExtraDessert::getName() {
    return baseProduct->getName() + " " + name;
}

float ExtraDessert::getPrice() {
    return price;
}
