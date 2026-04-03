//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/ExtraBeverage.h"

ExtraBeverage::ExtraBeverage(std::shared_ptr<Product>p, std::string name, float price): Extras(p, name , price) {

}

std::string ExtraBeverage::getName() {
    return baseProduct->getName() + " " + name;
}

float ExtraBeverage::getPrice() {
    return price;
}
