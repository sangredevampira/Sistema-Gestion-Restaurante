//
// Created by derek on 31/03/2026.
//

#include "../Entities headers/Restaurant.h"

#include "../Decorator Headers/Beverage.h"
#include "../Decorator Headers/Dessert.h"
#include "../Decorator Headers/Meal.h"
#include "../Decorator Headers/Beverage.h"
#include "../Decorator Headers/Dessert.h"
#include "../Decorator Headers/Extras.h"
#include "../Decorator Headers/MealExtra.h"
#include "../Decorator Headers/ExtraDessert.h"
#include "../Decorator Headers/ExtraBeverage.h"

Restaurant::Restaurant()
        : restaurantsName("GOJO'S ROOM")
{
        this->clientService = std::make_shared<ClientManagement>();
        this->productService = std::make_shared<ProductManagement>();
        this->orderManager = std::make_shared<OrderManagement>();
}

std::string Restaurant::getRestaurantsName() { return this->restaurantsName; }

std::shared_ptr<ClientManagement> Restaurant::getClientService() { return this->clientService; }

std::shared_ptr<ProductManagement> Restaurant::getProductService() {return this->productService; }

std::shared_ptr<OrderManagement> Restaurant::getOrderManager() { return this->orderManager; }
