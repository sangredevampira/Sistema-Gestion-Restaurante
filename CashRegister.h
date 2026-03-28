//
// Created by XPC on 27/3/2026.
//

#ifndef PROYECTO_1_CASHREGISTER_H
#define PROYECTO_1_CASHREGISTER_H

#include "Entities headers/PaymentMethod.h"

class CashRegister
{
public:
    static PaymentMethod* classifyPayment(int);
};


#endif //PROYECTO_1_CASHREGISTER_H