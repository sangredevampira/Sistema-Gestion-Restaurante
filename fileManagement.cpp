//
// Created by derek on 01/04/2026.
//

#include "fileManagement.h"

#include "dist/json/json.h"

bool fileManagement::saveToFile(std::shared_ptr<List<Client>> clientList, std::shared_ptr<List<Product>> productList,
                                std::shared_ptr<List<Order>> orderList) {

    Json::StreamWriterBuilder builder;
    builder["CommentStyle"] = "None";
    builder["Indentation"] = "   ";
    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

    std:: ofstream file("GestionRestaurante.txt");
    Json::Value event;
    Json::Value arreglo(Json::arrayValue);

    std::shared_ptr<Nodo<Client>> tempClients = clientList->getFirst();
    while (tempClients != nullptr) {
        Json::Value cliente;
        cliente["Name"] = tempClients->getElement()->getName();
        cliente["ID"] = tempClients->getElement()->getId();
        cliente["Phone"] = tempClients->getElement()->getPhone();
        arreglo.append(cliente);
        tempClients = tempClients->getNext();
    }

    std::shared_ptr<Nodo<Product>> tempProducts = productList->getFirst();
    while (tempProducts != nullptr) {
        Json::Value product;
        product["Name"] = tempProducts->getElement()->getName();
        product["Price"] = tempProducts->getElement()->getPrice();
        arreglo.append(product);
        tempProducts = tempProducts->getNext();
    }

    //hacer el de orders
}




bool fileManagement::loadFromFile(std::shared_ptr<List<Client>> &clientList,
    std::shared_ptr<List<Product>> &productList, std::shared_ptr<List<Order>> &orderList) {
}
