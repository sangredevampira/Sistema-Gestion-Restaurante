//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/SmallSize.h"

SmallSize::SmallSize(std::shared_ptr<Product>p,std::string name,float price): Extras(p, name, price){
}

std::string SmallSize::getName() {
    return baseProduct->getName() + " tamano mediano/a";
}

float SmallSize::getPrice() {
    return baseProduct->getPrice() + 0.050;
}

