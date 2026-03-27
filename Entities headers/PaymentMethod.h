//
// Created by derek on 24/03/2026.
//

#ifndef PROYECTO_PROGRA_DEREK_Y_KRIS_METODOPAGO_H
#define PROYECTO_PROGRA_DEREK_Y_KRIS_METODOPAGO_H

#include "../Utilities.h"

class PaymentMethod {
public:
    virtual std::string pay() = 0;
};


#endif //PROYECTO_PROGRA_DEREK_Y_KRIS_METODOPAGO_H