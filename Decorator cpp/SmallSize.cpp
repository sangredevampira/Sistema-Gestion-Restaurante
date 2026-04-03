//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/SmallSize.h"

SmallSize::SmallSize(std::string name,float price): Extras(name, price){
}

std::string SmallSize::getName() {
    return name;
}

float SmallSize::getPrice() {
    return price;
}

