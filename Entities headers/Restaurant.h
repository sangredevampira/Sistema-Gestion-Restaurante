//
// Created by derek on 31/03/2026.
//

#ifndef PROYECTO_1_KRIS_Y_DEREK_RESTAURANT_H
#define PROYECTO_1_KRIS_Y_DEREK_RESTAURANT_H

#include "../ListEntitie/List.h"
#include "ClientManagement.h"
#include "../Decorator Headers/ProductManagement.h"
#include "OrderManagement.h"
class Restaurant {
private:
    std::string restaurantsName;
    std::shared_ptr<ClientManagement> clientService;
    std::shared_ptr<ProductManagement> productService;
    std::shared_ptr<OrderManagement> orderManager;
public:
    Restaurant();
    std::string getRestaurantsName();
    std::shared_ptr<ClientManagement> getClientService();
    std::shared_ptr<ProductManagement> getProductService();
    std::shared_ptr<OrderManagement> getOrderManager();
};


#endif //PROYECTO_1_KRIS_Y_DEREK_RESTAURANT_H