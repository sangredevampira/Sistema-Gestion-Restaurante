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

std::shared_ptr<Product> MediumSize::clone() const
{
    auto copy = std::make_shared<MediumSize>(this->name, this->price);

    if (this->getExtras() != nullptr)
        copy->setExtras(this->getExtras()->clone());

    return copy;
}
