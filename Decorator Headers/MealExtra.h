//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAFOOD_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAFOOD_H

#include "Extras.h"
class MealExtra: public Extras{
    public:
    MealExtra(std::string name, float price);
    std::string getName() override;
    float getPrice() override;
    std::shared_ptr<Product> clone() const override;

};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRAFOOD_H