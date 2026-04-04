//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/BigSize.h"

BigSize::BigSize(std::string name,float price): Extras(name, price) {
}

std::string BigSize::getName() {
  return name;
}

float BigSize::getPrice() {
  return price;
}

std::shared_ptr<Product> BigSize::clone() const
{
  auto copy = std::make_shared<BigSize>(this->name, this->price);

  if (this->getExtras() != nullptr)
    copy->setExtras(this->getExtras()->clone());

  return copy;
}

