//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAS_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAS_H

#include "Product.h"
class Extras {
    protected:
    Product *baseProduct;
public:
    Extras(Product *baseProduct = nullptr);
    virtual ~Extras() = default;
    virtual std::string description() = 0;
    virtual float price() = 0;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAS_H