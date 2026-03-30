//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_MEDIUM_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_MEDIUM_H

#include "Extras.h"
class Medium: public Extras{
    public:
    Medium(Product *baseProduct = nullptr);
    std::string description() override;
    float price() override;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_MEDIUM_H