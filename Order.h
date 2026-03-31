//
// Created by XPC on 29/3/2026.
//

#ifndef PROYECTO_1_ORDER_H
#define PROYECTO_1_ORDER_H

#include "Entities headers/Client.h"
#include "Entities headers/PaymentMethod.h"
#include "Decorator Headers/Product.h"
#include "ListEntitie/List.h"

static int orderCounter = 1;

class Order
{
private:
    int orderID;
    std::shared_ptr<Client> client;
    std::shared_ptr<List<Product>> productsList;
    std::shared_ptr<PaymentMethod> payment;
    float total;
public:
    Order(std::shared_ptr<Client>, std::shared_ptr<PaymentMethod>);
    void setTotal(float);
    int getOrderID();
    std::shared_ptr<Client> getClient();
    std::shared_ptr<PaymentMethod> getPaymentMethod();
    std::shared_ptr<List<Product>> getProductsList();
    std::string addProductOrder(std::shared_ptr<Product>);
    std::string removeProductOrder(std::string);
    std::string showOrderProducts();
    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Order> client);};


#endif //PROYECTO_1_ORDER_H