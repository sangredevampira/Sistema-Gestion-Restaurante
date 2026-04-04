//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Meal.h"

Meal::Meal(std::string name, float price): Product(name, price) {
}

std::string Meal::getName() {
    return name;
}

float Meal::getPrice() {
    return price;
}

std::shared_ptr<Product> Meal::clone() const
{
    auto copy = std::make_shared<Meal>(this->name, this->price);

    if (this->getExtras() != nullptr)
        copy->setExtras(this->getExtras()->clone());

    return copy;
}
