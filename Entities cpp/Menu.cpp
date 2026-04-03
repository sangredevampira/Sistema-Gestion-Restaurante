//
// Created by derek on 31/03/2026.
//

#include "../Entities headers/Menu.h"

#include "../Exceptions/EmptyOrder.h"


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
    bool continueMenu = true;

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
                loadOrders(); break;
            case 5:
                saveOrders(); break;
            case 0:
                ConsoleService::clearConsole();
                finalMessage();
                continueMenu = false; break;
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

    }while (continueMenu);
}

void Menu::finalMessage()
{
    std::cout << "\t--------------------------------------------------------------------------------\n"
                << "\t * GRACIAS POR USAR EL SISTEMA DE GESTION DE PEDIDOS RESTAURANTE " << restaurant->getRestaurantsName() << " * \n"
                << "\t\t\t\t\t Hasta pronto! :)\n";
}

void Menu::createOrder()
{
    ConsoleService::clearConsole();
    std::string clientsName, productsName;
    int index, menuSize = restaurant->getProductService()->getProductList()->length();
    bool continueO = true;
    std::shared_ptr<Product> newProduct = nullptr;
    std::shared_ptr<Extras> newExtra = nullptr, tempExtra = nullptr;
    std::shared_ptr<List<Product>> products = std::make_shared<List<Product>>();
    std::shared_ptr<Order> newOrder = nullptr;
    

    std::cout << "------------------ * -------------------\n"
                << "              NUEVO PEDIDO\n"
                << "------------------ * -------------------\n";
    std::cout << "* Digita el nombre del cliente: "; std::cin.ignore(); std::getline(std::cin,clientsName);
    if (std::cin.fail() || clientsName == "") throw Miscapture();

    do
    {
        std::cout << "----------------------------------------\n"
                << "     MENU - RESTAURANTE GOJO'S ROOM\n"
                << "----------------------------------------\n";
        std::cout << restaurant->getProductService()->getProductList()->showList();
        std::cout << "* Digita el numero de producto deseado: "; std::cin >> index;

        if(index > menuSize) throw IndexOutOfRange();
        else
        {
            newProduct = restaurant->getProductService()->searchProduct(index);

            std::cout << "----------------------------------------\n"
                    << " MENU TAMANIOS - RESTAURANTE GOJO'S ROOM\n"
                    << "----------------------------------------\n"
                    << "(1) Tamanio grande\n"
                    << "(2) Tamanio mediano\n"
                    << "(3) Tamanio pequenio\n"
                    << "* Digita la opcion deseada: "; std::cin >> index;
            if (index < 1 || index > 3) throw IndexOutOfRange();
            else
            {
                newExtra = restaurant->getProductService()->classifySize(index);
                std::cout << newProduct->addExtraToProduct(newExtra) << "\n";
                std::cout << "\n";
            }

            std::cout << "* Deseas personalizar el producto?\n"
                    << "(1) Si\n"
                    << "(0) No\n"
                    << "* Digita la opcion deseada: "; std::cin >> index;

            if (index < 0 || index > 1) throw IndexOutOfRange();

            if (index == 1)
            {
                int max = restaurant->getProductService()->countExtrasByType(newProduct);

                do
                {
                    std::cout << "----------------------------------------\n"
                            << "       OPCIONES DE PERSONALIZACION\n"
                            << "----------------------------------------\n"
                    << "(1) Agregar ingredientes o extras\n"
                    << "(0) Remover ingredientes o extras\n"
                    << "* Digita la opcion deseada: "; std::cin >> index;

                if (index < 0 || index > 1) throw IndexOutOfRange();

                if (index == 1)                                                                                // AGREGAR EXTRAS AL PRODUCTO
                {
                    do
                    {
                        std::cout << "----------------------------------------\n"
                        << " MENU EXTRAS - RESTAURANTE GOJO'S ROOM\n"
                        << "----------------------------------------\n";
                        std::cout << restaurant->getProductService()->showExtrasByType(newProduct);
                        std::cout << "* Digita el numero de ingrediente o extra deseado: "; std::cin >> index;

                        if (index < 1 || index > max) throw IndexOutOfRange();

                        newExtra = restaurant->getProductService()->searchExtra(index, newProduct);
                        std::cout << newProduct->addExtraToProduct(newExtra) << "\n";
                        std::cout << "\n";

                        std::cout << "* Deseas agregar mas ingredientes?\n"
                        << "(1) Si\n"
                        << "(0) No\n"
                        << "* Digita la opcion deseada: "; std::cin >> index;

                        if (index < 0 || index > 1) throw IndexOutOfRange();

                    }while (index == 1);
                }else                                                                        // ELIMINAR EXTRAS DE UN PRODUCTO
                {
                    do
                    {
                        max = newProduct->getExtras()->length();
                        std::cout << "----------------------------------------\n"
                            << "     PERSONALIZACION - " << newProduct->getName() << "\n"
                            << "----------------------------------------\n"
                        << newProduct
                        << "* Digita el numero de ingrediente o extra a remover: "; std::cin >> index;

                        if(index < 1 || index > max) throw IndexOutOfRange();

                        tempExtra = newProduct->searchExtraByIndex(index);

                        if (tempExtra != nullptr)
                        {
                            std::cout << "----------------------------------------\n"
                            << "       INGREDIENTE ENCONTRADO\n"
                            << "----------------------------------------\n";
                            std::cout << tempExtra << "\n"
                            << "* Deseas remover este ingrediente?: \n"
                            << "(1) Si\n"
                            << "(0) No\n"
                            << "* Digita la opcion deseada: "; std::cin >> index;

                            if (index < 1 || index > max) throw IndexOutOfRange();
                            else
                                std::cout << newProduct->removeExtraFromProduct(tempExtra->getName()) << "\n\n";

                        }

                        std::cout << "* Deseas remover mas ingredientes?\n"
                          << "(1) Si\n"
                          << "(0) No\n"
                          << "* Digita la opcion deseada: "; std::cin >> index;

                        if (index < 0 || index > 1) throw IndexOutOfRange();
                    }while (index == 1);

                }

                    std::cout << "* Deseas continuar con la personalzacion?\n"
                        << "(1) Si\n"
                        << "(0) No\n"
                        << "* Digita la opcion deseada: "; std::cin >> index;

                    if (index < 0 || index > 1) throw IndexOutOfRange();

                }while (index == 1);

                                                                                                // UNA VEZ CONFIRMADO SE AGREGA
                products->insertFirst(newProduct);
                std::cout << "Producto agregado exitosamente!\n\n";
            }

            std::cout << "* Deseas agregar mas productos?\n"
                 << "(1) Si\n"
                << "(0) No\n"
                << "* Digita la opcion deseada: "; std::cin >> continueO;
        }
    }while (continueO);

    do
    {
        if (products == nullptr) throw EmptyOrder();

        newOrder = make_shared<Order>(clientsName, products);
        std::cout << "------------------ * -------------------\n"
              << "            DATOS DEL PEDIDO\n"
              << "------------------ * -------------------\n"
        << products->showList();









        std::cout << "* Deseas seguir editando el pedido?\n"
            << "(1) Si\n"
            << "(0) No\n"
            << "* Digita la opcion deseada: "; std::cin >> index;

        if (index < 0 || index > 1) throw IndexOutOfRange();

    }while (index == 1);
}

void Menu::registerClient()
{
    ConsoleService::clearConsole();
    std::string name, phone, id;
    int confirm;

    try
    {
        std::cout << "------------------ * -------------------\n"
                << "     INGRESA LOS DATOS DEL CLIENTE\n"
                << "------------------ * -------------------\n";
        std::cout << "* Digita el nombre completo: "; std::cin.ignore(); std::getline(std::cin,name);
        if (std::cin.fail()) throw Miscapture();
        std::cout << "* Digita el numero telefonico: "; std::cin >> phone;
        if (std::cin.fail()) throw Miscapture();
        std::cout << "* Digita el numero de identificacion: "; std::cin.ignore(); std::getline(std::cin,id);
        if (std::cin.fail()) throw Miscapture();

        std::cout << "----------------------------------------\n";

        if (name == "" || id == "")
        {
            std::cout << "    No se puedo registrar el cliente\n";
        }else
            std::cout << "     " << restaurant->getClientService()->addClient(name, id, phone);

        std::cout << "------------------ * -------------------\n";

        ConsoleService::pause();
        ConsoleService::clearConsole();

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

void Menu::loadOrders() {
    try {
        ConsoleService::clearConsole();

        if (restaurant == nullptr) {
            throw std::runtime_error("El restaurante no esta inicializado.");
        }

        std::shared_ptr<ClientManagement> clientSvc = restaurant->getClientService();
        std::shared_ptr<ProductManagement> productSvc = restaurant->getProductService();
        std::shared_ptr<OrderManagement> orderSvc = restaurant->getOrderManager();
        if (clientSvc == nullptr || productSvc == nullptr || orderSvc == nullptr) {
            throw std::runtime_error("Servicios del restaurante no inicializados.");
        }

        std::shared_ptr<List<Client>> clientList = clientSvc->getClientList();
        std::shared_ptr<List<Product>> productList = productSvc->getProductList();
        std::shared_ptr<List<Order>> orderList = orderSvc->getOrderList();
        if (clientList == nullptr || productList == nullptr || orderList == nullptr) {
            throw std::runtime_error("Listas no inicializadas.");
        }

        fileManagement fm;
        fm.loadFromFile(clientList, productList, orderList);

        std::cout << "\n* Pedidos cargados desde 'GestionRestaurante.txt'\n";
        std::cout << "* Presiona Enter para continuar...";
        std::cin.ignore(1000, '\n');
        std::cin.get();
        ConsoleService::clearConsole();

    } catch (std::exception& e) {
        ConsoleService::clearConsole();
        std::cout << "ERROR al cargar: " << e.what() << '\n';
        std::cout << "* Presiona Enter para continuar...";
        std::cin.ignore(1000, '\n');
        std::cin.get();
        ConsoleService::clearConsole();
    }
}

void Menu::saveOrders() {
    try {
        ConsoleService::clearConsole();

        if (restaurant == nullptr) {
            throw std::runtime_error("El restaurante no esta inicializado.");
        }

        std::shared_ptr<ClientManagement> clientSvc = restaurant->getClientService();
        std::shared_ptr<ProductManagement> productSvc = restaurant->getProductService();
        std::shared_ptr<OrderManagement> orderSvc = restaurant->getOrderManager();
        if (clientSvc == nullptr || productSvc == nullptr || orderSvc == nullptr) {
            throw std::runtime_error("Servicios del restaurante no inicializados.");
        }

        std::shared_ptr<List<Client>> clientList = clientSvc->getClientList();
        std::shared_ptr<List<Product>> productList = productSvc->getProductList();
        std::shared_ptr<List<Order>> orderList = orderSvc->getOrderList();
        if (clientList == nullptr || productList == nullptr || orderList == nullptr) {
            throw std::runtime_error("Listas no inicializadas.");
        }

        fileManagement fm;
        fm.saveToFile(clientList, productList, orderList);

        std::cout << "\n* Pedidos guardados en 'GestionRestaurante.txt'\n";
        std::cout << "* Presiona Enter para continuar...";
        std::cin.ignore(1000, '\n');
        std::cin.get();
        ConsoleService::clearConsole();

    } catch (std::exception& e) {
        ConsoleService::clearConsole();
        std::cout << "ERROR al guardar: " << e.what() << '\n';
        std::cout << "* Presiona Enter para continuar...";
        std::cin.ignore(1000, '\n');
        std::cin.get();
        ConsoleService::clearConsole();
    }

}


