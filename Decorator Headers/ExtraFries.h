//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAFRIES_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAFRIES_H

#include "MealExtra.h"
class ExtraFries :public MealExtra{
    public:
    ExtraFries(std::shared_ptr<Product> baseProduct);
    virtual std::string description() override;
    virtual float price() override;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAFRIES_H