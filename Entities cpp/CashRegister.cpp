//
// Created by XPC on 27/3/2026.
//

#include "../Entities headers/CashRegister.h"


std::shared_ptr<PaymentMethod> CashRegister::classifyPayment(int index)
{
    std::shared_ptr<PaymentMethod> selected = nullptr;
    switch (index)
    {
    case 1:
        selected = std::make_shared<Card>(); break;
    case 2:
        selected = std::make_shared<Cash>(); break;
    case 3:
        selected = std::make_shared<Digital>(); break;
    }

    return selected;
}