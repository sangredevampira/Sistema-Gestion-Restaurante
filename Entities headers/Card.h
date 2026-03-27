//
// Created by derek on 24/03/2026.
//

#ifndef PROYECTO_PROGRA_DEREK_Y_KRIS_CARD_H
#define PROYECTO_PROGRA_DEREK_Y_KRIS_CARD_H

#include "../Entities headers/PaymentMethod.h"


class Card : public PaymentMethod
{
public:
    virtual std::string pay() override;
};


#endif //PROYECTO_PROGRA_DEREK_Y_KRIS_CARD_H