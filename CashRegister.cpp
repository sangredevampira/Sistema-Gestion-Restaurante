//
// Created by XPC on 27/3/2026.
//

#include "CashRegister.h"
#include "Entities headers/Card.h"
#include "Entities headers/Cash.h"
#include "Entities headers/Digital.h"

PaymentMethod* CashRegister::classifyPayment(int index)
{
    try{
        PaymentMethod* selected = nullptr;
        switch (index)
        {
        case 1:
            selected = new Card(); break;
        case 2:
            selected = new Cash(); break;
        case 3:
            selected = new Digital(); break;
        default:

        }
    }catch ()
    {

    }
}
