//
// Created by derek on 31/03/2026.
//

#include "Menu.h"

Menu::Menu() { this->restaurant = std::make_unique<Restaurant>(); }

void Menu::mainMenu()
{
    std::cout << "===================================\n"
            << " * SISTEMA DE GESTION DE PEDIDOS *\n"
            << "     RESTAURANTE " << restaurant->getRestaurantsName() << "\n"
            << "===================================\n"
            << "(1) Submenu pedidos" << "\n"
            << "(2) Submenu clientes" << "\n"
            << "(3) Submenu productos" << "\n"
            << "(4) Cargar pedidos" << "\n"
            << "(5) Guardar" << "\n"
            << "(0) Salir" << "\n"
            << "* Digita la opcion deseada: ";
}

void Menu::actionsMainMenu()
{
    int option;
    bool quit = false;

    do
    {
        try
        {
            mainMenu();
            std::cin>>option;
            if (std::cin.fail()) throw Miscapture();

            switch (option)
            {
            case 1:
                    actionsSubmenuOrders(); break;
                case 2:
                    actionsSubmenuClients(); break;
                case 3:
                    actionsSubmenuProducts(); break;
                case 4:
                case 5:
            case 0:
                    ConsoleService::clearConsole();
                    std::cout << "\t * GRACIAS POR USAR EL SISTEMA DE GESTION DE PEDIDOS RESTAURANTE " << restaurant->getRestaurantsName() << " * \n"
                                << "\t\t\t\t\t Hasta pronto! :)\n";
                    quit = true; break;
                default:
                    throw IndexOutOfRange();
            }


        }catch (std::exception& e)
        {
            std::cout << "ERROR: " << e.what() << '\n';

            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

    }while (!quit);
}

void Menu::submenuOrders()
{

}

void Menu::actionsSubmenuOrders()
{

}

void Menu::submenuClients()
{
}

void Menu::actionsSubmenuClients()
{
}

void Menu::submenuProducts()
{
}

void Menu::actionsSubmenuProducts()
{
}
