//
// Created by XPC on 29/3/2026.
//

#include "Order.h"

Order::Order(std::shared_ptr<Client> client, std::shared_ptr<PaymentMethod> selected)
    : client(client), payment(selected)
{ this->orderID = orderCounter++; }

std::string Order::addProductOrder(std::shared_ptr<Product> product)
{
    productsList->insertFirst(product);
    return "Producto agregado correctamente!\n";
}

std::string Order::removeProductOrder(std::string productName)
{
    productsList->deleteElement()
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Order> client)
{
}
