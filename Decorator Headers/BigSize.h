//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_BIG_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_BIG_H

#include "Extras.h"
class BigSize:public Extras {
public: BigSize(std::string name, float price);
    std::string getName() override;
    float getPrice() override;
    std::shared_ptr<Product> clone() const override;
};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_BIG_H