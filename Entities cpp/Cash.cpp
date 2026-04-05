//
// Created by derek on 24/03/2026.
//

#include "../Entities headers/Cash.h"

std::string Cash::pay(float amount, float totalPrice)
{
    std::stringstream ss;
    try
    {
        if (amount < totalPrice) throw Underpayment();

        int change = amount - totalPrice;

        ss << "Pago realizado en efectivo\n";
        if (change == 0) ss << "No hay vuelto \n";
        else
        {
            ss << "Vuelto: " << change << " colones" <<"\n"
            << "Se devuelve en:\n";

            int denominations[] = {10000, 5000, 2000, 1000, 500, 100, 50, 25, 10, 5};

            for (int i = 0; i < 8; i++)
            {
                int quantity = change / denominations[i];
                change %= denominations[i];

                if (quantity > 0)
                {
                    if (denominations[i] >= 1000)
                    {
                        if (quantity == 1)
                            ss << "\t" << quantity << " billete de " << denominations[i] << " colones\n";
                        else
                            ss << "\t" << quantity << " billetes de " << denominations[i] << " colones\n";
                    }
                    else
                    {
                        if (quantity == 1)
                            ss << "\t" << quantity << " moneda de " << denominations[i] << " colones\n";
                        else
                            ss << "\t" << quantity << " monedas de " << denominations[i] << " colones\n";
                    }
                }
            }
        }
    }catch(GeneralException& e)
    {
        ss << "ERROR: " << e.what() << '\n';
    }

    return ss.str();
}
