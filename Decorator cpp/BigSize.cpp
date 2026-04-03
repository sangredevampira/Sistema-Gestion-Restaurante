//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/BigSize.h"

BigSize::BigSize(std::shared_ptr<Product>p, std::string name,float price): Extras(p, name, price) {
}

std::string BigSize::getName() {
  return baseProduct->getName() + "tamaño grande.";
}

float BigSize::getPrice() {
  return baseProduct->getPrice() + 0.075;
}

