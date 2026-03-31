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
    std::shared_ptr<Client> client;
    std::shared_ptr<List<Product>> productsList;
    std::shared_ptr<PaymentMethod> payment;
public:
    Order(std::shared_ptr<Client>, std::shared_ptr<PaymentMethod>);
    std::string addProductOrder(std::shared_ptr<Product>);
    std::string removeProductOrder(std::string);
    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Order> client);};


#endif //PROYECTO_1_ORDER_H