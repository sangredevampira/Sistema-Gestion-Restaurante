//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAFRIES_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAFRIES_H

#include "ExtraFood.h"
class ExtraFries :public ExtraFood{
    public:
    ExtraFries(Product *baseProduct = nullptr);
    virtual std::string description() override;
    virtual float price() override;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAFRIES_H