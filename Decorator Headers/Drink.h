//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_DRINK_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_DRINK_H
#include "Product.h"


class Drink : public Product {
public:
    Drink(std::string name = "", float price = 0.0);
    std::string getName() override;
    float getPrice() override;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_DRINK_H