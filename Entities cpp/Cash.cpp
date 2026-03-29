//
// Created by derek on 24/03/2026.
//

#include "../Entities headers/Cash.h"

std::string Cash::pay(float amount, float totalPrice)
{
    std::stringstream ss;
    try
    {
        ss << "Pago realizado en efectivo\n";
        if (amount < totalPrice) throw Underpayment();

        float change = amount - totalPrice;
        if (change == 0) ss << "No hay vuelo \n";


    }catch(GeneralException& e)
    {
        ss << "ERROR: " << e.what() << '\n';
    }

    return ss.str();
}
