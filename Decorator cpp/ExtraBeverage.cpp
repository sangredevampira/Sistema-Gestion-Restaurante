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
