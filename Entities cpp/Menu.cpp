//
// Created by derek on 31/03/2026.
//

#include "../Entities headers/Menu.h"

Menu::Menu() { this->restaurant = std::make_unique<Restaurant>(); }

void Menu::mainMenu()
{
    std::cout << "=======================================\n"
            << "  * SISTEMA DE GESTION DE PEDIDOS *\n"
            << "       RESTAURANTE " << restaurant->getRestaurantsName() << "\n"
            << "=======================================\n"
            << "(1) Crear un pedido" << "\n"
            << "(2) Registrar cliente" << "\n"
            << "(3) Agregar un producto" << "\n"
            << "(4) Cargar pedidos" << "\n"
            << "(5) Guardar pedidos" << "\n"
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
                createOrder(); break;
            case 2:
                registerClient(); break;
            case 3:
                addProduct(); break;
            case 4:

            case 5:

            case 0:
                ConsoleService::clearConsole();
                finalMessage();
                quit = true; break;
            default:
                throw IndexOutOfRange();
            }
        }catch (std::exception& e)
        {
            ConsoleService::clearConsole();
            std::cout << "ERROR: " << e.what() << '\n';
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

    }while (!quit);
}

void Menu::finalMessage()
{
    std::cout << "\t--------------------------------------------------------------------------------\n"
                << "\t * GRACIAS POR USAR EL SISTEMA DE GESTION DE PEDIDOS RESTAURANTE " << restaurant->getRestaurantsName() << " * \n"
                << "\t\t\t\t\t Hasta pronto! :)\n";
}

void Menu::createOrder()
{

}

void Menu::registerClient()
{
    ConsoleService::clearConsole();
    std::string name, phone, id;

    try
    {
        std::cout << "------------------ * ------------------\n"
                << "     INGRESA LOS DATOS DEL CLIENTE\n"
                << "------------------ * ------------------\n";
        std::cout << "* Digita el nombre completo: "; std::getline(std::cin,name);
        if (std::cin.fail()) throw Miscapture();
        std::cout << "* Digita el numero telefonico sin espacios ni guiones: "; std::cin >> phone;
        if (std::cin.fail()) throw Miscapture();
        std::cout << "* Digita el numero telefonico sin espacios ni guiones: "; std::cin >> phone;
        if (std::cin.fail()) throw Miscapture();

    }catch (std::exception& e)
    {
        ConsoleService::clearConsole();
        std::cout << "ERROR: " << e.what() << '\n';
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

}

void Menu::addProduct()
{
}


