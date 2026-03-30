    //
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_LITTLE_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_LITTLE_H

#include "Extras.h"
    class Little:public Extras{
public:
    Little(Product *baseProduct = nullptr);
    std::string description() override;
    float price() override;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_LITTLE_H