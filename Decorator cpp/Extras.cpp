//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Extras.h"

Extras::Extras(std::string name, float price) : Product(name, price)
{}


std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Extras> extras) {

    os << extras->getName() << " (" << extras->getPrice() << ")";
    return os;
}
