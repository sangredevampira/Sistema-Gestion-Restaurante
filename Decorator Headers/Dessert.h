//
// Created by derek on 28/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_DESSERT_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_DESSERT_H
#include "Product.h"


class Dessert : public Product{
    public:
    Dessert(std::string name = "", float price = 0.0);
    std::string getName() override;
    float getPrice() override;

};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_DESSERT_H