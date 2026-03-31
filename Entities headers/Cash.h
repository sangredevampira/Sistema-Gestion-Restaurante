//
// Created by derek on 24/03/2026.
//

#ifndef PROYECTO_PROGRA_DEREK_Y_KRIS_CASH_H
#define PROYECTO_PROGRA_DEREK_Y_KRIS_CASH_H

#include "../Entities headers/PaymentMethod.h"
#include "../Exceptions/Underpayment.h"

class Cash : public PaymentMethod
{
public:
      std::string pay(float, float) override;

};


#endif //PROYECTO_PROGRA_DEREK_Y_KRIS_CASH_H