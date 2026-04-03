//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/ExtraDessert.h"

ExtraDessert::ExtraDessert(std::string name, float price): Extras(name, price) {
}

std::string ExtraDessert::getName() {
    return name;
}

float ExtraDessert::getPrice() {
    return price;
}
