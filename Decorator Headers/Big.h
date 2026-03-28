//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_BIG_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_BIG_H

#include "Extras.h"
class Big:public Extras {
public: Big(Product *baseProduct = nullptr);
    virtual ~Big();
    std::string description() override;
    float price() override;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_BIG_H