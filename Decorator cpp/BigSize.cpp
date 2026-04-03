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

