//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_DRINK_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_DRINK_H
#include "Product.h"


class Beverage : public Product {
public:
    Beverage(std::string name = "", float price = 0.0);
    std::string getName() override;
    float getPrice() override;
    std::shared_ptr<Product> clone() const override;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_DRINK_H