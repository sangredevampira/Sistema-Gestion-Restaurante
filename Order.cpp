//
// Created by XPC on 29/3/2026.
//

#include "Order.h"

Order::Order(std::shared_ptr<Client> client, std::shared_ptr<PaymentMethod> selected)
    : client(client), payment(selected)
{ this->orderID = orderCounter++; }

void Order::setTotal(float total) { this->total = total; }

int Order::getOrderID() { return orderID; }

std::shared_ptr<Client> Order::getClient() { return client; }

std::shared_ptr<PaymentMethod> Order::getPaymentMethod() { return payment; }

std::shared_ptr<List<Product>> Order::getProductsList() { return productsList; }

std::string Order::addProductOrder(std::shared_ptr<Product> product)
{
    productsList->insertFirst(product);
    return "Producto agregado correctamente!\n";
}

std::string Order::removeProductOrder(std::string productName)
{

}

std::string Order::showOrderProducts() { return getProductsList()->showList(); }

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Order> order)
{
    os << "\t** ORDEN No. " << order->getOrderID() << " ***" << "\n";
    os << "* Cliente: " << order->getClient()->getName() << "\n";
    os << "* LISTA DE PRODUCTOS *" << "\n"
        << order->showOrderProducts();
    return os;
}
