//
// Created by derek on 27/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_PRODUCT_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_PRODUCT_H

#include "../Utilities/Utilities.h"
class Product {
protected:
    std::string name;
    float price;
    public:
    Product(std::string name = "", float price = 0.0);
    virtual ~Product() = default;
    virtual std::string getName() = 0;
    virtual float getPrice() = 0;

};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_PRODUCT_H