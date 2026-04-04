//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/ExtraBeverage.h"

ExtraBeverage::ExtraBeverage(std::string name, float price)
    : Extras(name , price) {

}

std::string ExtraBeverage::getName() {
    return name;
}

float ExtraBeverage::getPrice() {
    return price;
}

std::shared_ptr<Product> ExtraBeverage::clone() const
{
    auto copy = std::make_shared<ExtraBeverage>(this->name, this->price);

    if (this->getExtras() != nullptr)
        copy->setExtras(this->getExtras()->clone());

    return copy;
}
