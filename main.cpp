//
// Created by derek on 27/03/2026.
//

#include "Entities headers/Client.h"
#include "Entities headers/Card.h"
#include "Entities headers/Cash.h"
#include "Entities headers/Digital.h"
#include "TemplateList/Lista.h"
#include "Entities headers/PaymentMethod.h"
int main() {
    Client *C1 = new Client("Derek", "86569980", "208680976");

    List<Client > *listaCliente = new List<Client>;
    listaCliente->insertarInicio(C1);
    std::cout << listaCliente->toStringLista() << std::endl;

    std::cout << std::endl;

    PaymentMethod *card = new Card();
    PaymentMethod *cash = new Cash();
    PaymentMethod *digital = new Digital();

    List<PaymentMethod > *listaPaymentMethod = new List<PaymentMethod>;
    listaPaymentMethod->insertarInicio(card);
    listaPaymentMethod->insertarInicio(cash);
    listaPaymentMethod->insertarInicio(digital);
    if (listaPaymentMethod->estaVacio()) {
        std::cout << "La lista de métodos de pago está vacía." << std::endl;
    } else {
        std::cout << "La lista de métodos de pago no está vacía." << std::endl;
    }
    std::cout << std::endl;

    return 0;

}