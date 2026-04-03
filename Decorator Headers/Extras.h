//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAS_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAS_H

#include "Product.h"
class Extras : public Product {
protected:

public:
    Extras(std::string name, float price);
    virtual std::string getName() = 0;
    virtual float getPrice() = 0;
    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Extras> extras); // operador sobrecargado

};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAS_H