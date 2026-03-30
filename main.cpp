//
// Created by derek on 27/03/2026.
//

#include "Entities headers/Cash.h"
#include <memory>

int main() {

    std::shared_ptr<Cash> c = std::make_shared<Cash>();

    std::cout << c->pay(10000, 7500);


}