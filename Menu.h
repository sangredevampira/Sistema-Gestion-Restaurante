//
// Created by derek on 31/03/2026.
//

#ifndef PROYECTO_1_KRIS_Y_DEREK_MENU_H
#define PROYECTO_1_KRIS_Y_DEREK_MENU_H

#include "Entities headers/Restaurant.h"
#include "Utilities/ConsoleService.h"
#include "Exceptions/Miscapture.h"
#include "Exceptions/IndexOutOfRange.h"

class Menu {
private:
    std::unique_ptr<Restaurant> restaurant;
public:
    Menu();

    //Menu principal
    void mainMenu();
    void actionsMainMenu();

    //Submenu pedidos
    void submenuOrders();
    void actionsSubmenuOrders();

    //Submenu clientes
    void submenuClients();
    void actionsSubmenuClients();

    //Submenu productos
    void submenuProducts();
    void actionsSubmenuProducts();

    //Cargar pedidos

    //Guardar
};


#endif //PROYECTO_1_KRIS_Y_DEREK_MENU_H