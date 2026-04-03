//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRADRINK_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRADRINK_H

#include "Extras.h"
class ExtraBeverage : public Extras {
    public:
    ExtraBeverage(std::string name, float price);
    std::string getName() override;
    float getPrice() override;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_EXTRADRINK_H