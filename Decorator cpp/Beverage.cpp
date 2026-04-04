//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Beverage.h"

Beverage::Beverage(std::string name, float price):Product(name, price) {
}

std::string Beverage::getName() {
    return name;
}

float Beverage::getPrice() {
    return price;
}

std::shared_ptr<Product> Beverage::clone() const
{
    auto copy = std::make_shared<Beverage>(this->name, this->price);

    if (this->getExtras() != nullptr)
        copy->setExtras(this->getExtras()->clone());

    return copy;
}
