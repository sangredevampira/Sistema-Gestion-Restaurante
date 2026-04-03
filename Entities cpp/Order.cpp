//
// Created by XPC on 29/3/2026.
//

#include "../Entities headers/Order.h"

Order::Order(std::string clientsName, std::shared_ptr<List<Product>> productsList, std::shared_ptr<PaymentMethod> selected)
    : clientsName(clientsName), productsList(productsList), payment(selected), orderID(orderCounter++)
{ calculateTotalPrice(this->clientsName); }


Order::Order(std::string clientsName, std::shared_ptr<List<Product>> productsList)
    : orderID(orderCounter), clientsName(clientsName), productsList(productsList)
{
    calculateTotalPrice(this->clientsName);
    payment = nullptr;
}

Order::Order(int orderID, std::string clientsName, std::shared_ptr<List<Product>> productsList, std::shared_ptr<PaymentMethod>payment, float totalPrice){
    this->orderID = orderID;
    this->clientsName = clientsName;
    this->productsList = productsList;
    this->payment = payment;
    this->totalPrice = totalPrice;
}




int Order::getOrderID() { return orderID;}

std::string Order::getClientsName() { return clientsName;}

std::shared_ptr<List<Product>> Order::getProductsList() { return productsList; }

std::shared_ptr<PaymentMethod> Order::getPaymentMethod() { return payment; }

void Order::setPaymentMethod(std::shared_ptr<PaymentMethod> paymentMethod)
{ payment = paymentMethod; }

float Order::getTotalPrice() {
    return totalPrice;
}


std::string Order::addProductOrder(std::shared_ptr<Product> product)
{
    productsList->insertFirst(product);
    return "Producto agregado correctamente!\n";
}

std::string Order::removeProductOrder(std::string productName)
{
    std::string messaje;
    std::shared_ptr<Nodo<Product>> temp = productsList->getFirst();
    while (temp != nullptr)
    {
        if (temp->getNext()->getElement()->getName() == productName)
        {
            temp->setNext(temp->getNext()->getNext());
            messaje = "Producto eliminado correctamente\n";
        }else
            messaje = "Producto no encontrado\n";
    }
    return messaje;
}

std::string Order::calculateTotalPrice(std::string clientName)
{
    std::shared_ptr<Nodo<Product>> temp = productsList->getFirst();
    while (temp != nullptr)
    {
        totalPrice += temp->getElement()->getPrice();
    }
    if (clientName != "")
    {
        totalPrice -= (totalPrice * 0.15);
        return "Aplica 15% de descuento";
    }
    return "No aplica";
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Order> order)
{
    os << "*********************************\n";
    os << "  ORDEN No. " << order->getOrderID() << "\n";
    if (order->getClientsName() != "")
        os << "* Cliente: " << order->getClientsName() << "\n";
    os << "* Productos seleccionados:\n";
    os << order->getProductsList()->showList();
    os << "* Descuento: " << order->getTotalPrice() << "\n";
    os << "* Total a pagar:" << order->getTotalPrice() << "\n";
    return os;
}
