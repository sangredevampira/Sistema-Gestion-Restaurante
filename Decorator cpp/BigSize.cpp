//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/BigSize.h"

BigSize::BigSize(std::shared_ptr<Product>p): Extras(p) {

}

std::string BigSize::getName() {
  return baseProduct->getName() + " tamaño grande. ";
}

float BigSize::getPrice() {
  return baseProduct->getPrice() + 0.075;
}

