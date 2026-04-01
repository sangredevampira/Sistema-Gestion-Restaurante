//
// Created by derek on 31/03/2026.
//

#include "Menu.h"

Menu::Menu() { this->restaurant = std::make_unique<Restaurant>(); }

void Menu::pause()
{
    std::cout << "\nPresiona ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Menu::clearConsole() { std::cout << std::string(50, '\n'); }

void Menu::mainMenu()
{
    std::cout << "===================================\n"
            << " * SISTEMA DE GESTION DE PEDIDOS *\n"
            << "\t " << "RESTAURANTE" << restaurant->getRestaurantsName() << "\n"
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
            if (std::cin.fail()) throw

        }catch (std::exception& e)
        {

        }

    }while (!quit);
}
