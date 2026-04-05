//
// Created by derek on 31/03/2026.
//

#ifndef PROYECTO_1_KRIS_Y_DEREK_MENU_H
#define PROYECTO_1_KRIS_Y_DEREK_MENU_H

#include "Restaurant.h"
#include "../Utilities/ConsoleService.h"
#include "../Exceptions/Miscapture.h"
#include "../Exceptions/IndexOutOfRange.h"
#include "../fileManagement.h"
#include "..//Entities headers/CashRegister.h"


class Menu {
private:
    std::unique_ptr<Restaurant> restaurant;
public:
    Menu();

    void mainMenu();
    void actionsMainMenu();
    void finalMessage();

    void ordersMenu();

    void clientMenu();

    void productMenu();

    void loadOrders();
    void saveOrders();
};


#endif //PROYECTO_1_KRIS_Y_DEREK_MENU_H