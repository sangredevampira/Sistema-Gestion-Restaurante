//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Big.h"

Big::Big(Product *baseProduct): Extras(baseProduct) {

}

Big::~Big() {
}

std::string Big::description() {
  return baseProduct->getName() + "Grande";
}

float Big::price() {
  return baseProduct->getPrice() + 0.075;
}
