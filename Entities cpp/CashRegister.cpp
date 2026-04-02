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

std::string CashRegister::availablePaymentMethods()
{
    std::stringstream ss;
    ss << "---* METODOS DE PAGO DISPONIBLES *---\n";
    ss << "1. Tarjeta\n";
    ss << "2. Efectivo\n";
    ss << "3. Digital SinpeMovil\n";
    ss << "Digita la opcion deseada: ";
    return ss.str();
}
