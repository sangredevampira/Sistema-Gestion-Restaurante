//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAS_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAS_H

#include "Product.h"
class Extras {
    protected:
    std::shared_ptr<Product> baseProduct;
public:
    Extras(std::shared_ptr<Product> p);
    virtual std::string description() = 0;
    virtual float price() = 0;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAS_H