//
// Created by derek on 31/03/2026.
//

#include "../Entities headers/OrderManagement.h"

OrderManagement::OrderManagement() { ordersList = std::make_shared<List<Order>>(); }

std::string OrderManagement::placeOrder(std::string clientsName, std::shared_ptr<List<Product>> productsList, int index)
{
    std::shared_ptr payment = CashRegister::classifyPayment(index);
    std::shared_ptr<Order> newOrder = std::make_shared<Order>(clientsName, productsList, payment);
    ordersList->insertFirst(newOrder);
    return "Orden aceptada correctamente\n";
}


std::shared_ptr<Order> OrderManagement::searchOrder(int id)
{
    bool found = false;
    std::shared_ptr<Order> searched = nullptr;
    std::shared_ptr<Nodo<Order>> current = ordersList->getFirst();
    while (!found && current != nullptr){
        if (current->getElement()->getOrderID() == id)
        {
            found = true;
            searched = current->getElement();

        }else current = current->getNext();
    }
    return searched;

}

std::shared_ptr<List<Order>> OrderManagement::getOrderList() {
    return ordersList;
}

