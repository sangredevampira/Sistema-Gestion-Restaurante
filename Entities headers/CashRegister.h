//
// Created by XPC on 27/3/2026.
//

#ifndef PROYECTO_1_CASHREGISTER_H
#define PROYECTO_1_CASHREGISTER_H

#include "PaymentMethod.h"
#include "Card.h"
#include "Cash.h"
#include "Digital.h"
#include "../Exceptions/IndexOutOfRange.h"

class CashRegister
{
public:
    static std::shared_ptr<PaymentMethod> classifyPayment(int);
};


#endif //PROYECTO_1_CASHREGISTER_H