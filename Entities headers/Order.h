//
// Created by XPC on 29/3/2026.
//

#ifndef PROYECTO_1_ORDER_H
#define PROYECTO_1_ORDER_H

#include "Client.h"
#include "PaymentMethod.h"
#include "../Decorator Headers/Product.h"
#include "../ListEntitie/List.h"

static int orderCounter = 1;

class Order
{
private:
    int orderID;
    std::string clientsName;
    std::shared_ptr<List<Product>> productsList;
    std::shared_ptr<PaymentMethod> payment;
    float totalPrice;
public:
    Order(std::string, std::shared_ptr<PaymentMethod>);
    int getOrderID();
    std::string getClientsName();
    std::shared_ptr<List<Product>> getProductsList();
    std::shared_ptr<PaymentMethod> getPaymentMethod();
    std::string addProductOrder(std::shared_ptr<Product>);
    std::string removeProductOrder(std::string);
    float getTotalPrice();
    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Order> client);

};

#endif //PROYECTO_1_ORDER_H