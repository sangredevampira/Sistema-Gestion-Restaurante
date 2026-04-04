//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Dessert.h"

Dessert::Dessert(std::string name, float price): Product(name, price) {
}

std::string Dessert::getName() {
    return name;
}

float Dessert::getPrice() {
    return price;
}

std::shared_ptr<Product> Dessert::clone() const
{
    auto copy = std::make_shared<Dessert>(this->name, this->price);

    if (this->getExtras() != nullptr)
        copy->setExtras(this->getExtras()->clone());

    return copy;
}
