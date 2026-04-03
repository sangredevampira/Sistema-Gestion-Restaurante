//
// Created by derek on 31/03/2026.
//

#ifndef PROYECTO_1_KRIS_Y_DEREK_ORDERMANAGEMENT_H
#define PROYECTO_1_KRIS_Y_DEREK_ORDERMANAGEMENT_H

#include "Order.h"
#include "CashRegister.h"

class OrderManagement {
private:
    std::shared_ptr<List<Order>> ordersList;
public:
    OrderManagement();
    std::string placeOrder(std::shared_ptr<Order>, int);
    std::shared_ptr<Order> searchOrder(int);
    std::shared_ptr<List<Order>> getOrderList();

};


#endif //PROYECTO_1_KRIS_Y_DEREK_ORDERMANAGEMENT_H