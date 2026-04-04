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

std::shared_ptr<Product> SmallSize::clone() const
{
    auto copy = std::make_shared<SmallSize>(this->name, this->price);

    if (this->getExtras() != nullptr)
        copy->setExtras(this->getExtras()->clone());

    return copy;
}

