//
// Created by derek on 24/03/2026.
//

#ifndef PROYECTO_PROGRA_DEREK_Y_KRIS_METODOPAGO_H
#define PROYECTO_PROGRA_DEREK_Y_KRIS_METODOPAGO_H

#include "../Utilities/Utilities.h"

class PaymentMethod {
public:
    virtual std::string pay(float, float) = 0;
};


#endif //PROYECTO_PROGRA_DEREK_Y_KRIS_METODOPAGO_H