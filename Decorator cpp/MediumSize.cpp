//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/MediumSize.h"

MediumSize::MediumSize(std::string name, float price): Extras(name, price) {
}

std::string MediumSize::getName() {
    return name;
}

float MediumSize::getPrice() {
    return price;
}
