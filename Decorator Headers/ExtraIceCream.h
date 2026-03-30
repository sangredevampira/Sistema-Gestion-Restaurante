//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAICECREAM_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAICECREAM_H

#include "ExtraDessert.h"
class ExtraIceCream:public ExtraDessert {
    public:
    ExtraIceCream(std::shared_ptr<Product> p);
    virtual std::string description() override;
    virtual float price() override;
    virtual std::string getName() override;
    virtual float getPrice() override;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAICECREAM_H