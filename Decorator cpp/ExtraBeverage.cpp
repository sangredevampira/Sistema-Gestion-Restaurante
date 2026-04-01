//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/ExtraBeverage.h"

ExtraBeverage::ExtraBeverage(std::shared_ptr<Product>p): Extras(p) {

}

std::string ExtraBeverage::getName() {
    return baseProduct->getName() + "con hielo extra";
}

float ExtraBeverage::getPrice() {
    return baseProduct->getPrice() + 0.005;
}
