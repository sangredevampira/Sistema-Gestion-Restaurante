//
// Created by derek on 01/04/2026.
//

#include "fileManagement.h"

#include "dist/json/json.h"

std::string fileManagement::saveToFile(std::shared_ptr<List<Client>> clientList, std::shared_ptr<List<Product>> productList,
                                std::shared_ptr<List<Order>> orderList) {

        Json::StreamWriterBuilder builder;
        builder["CommentStyle"] = "None";
        builder["Indentation"] = "   ";
        std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

        std:: ofstream file("GestionRestaurante.txt");
        Json::Value event;
        event["Clients"] = convertClientListToJson(clientList);
        event["Products"] = convertProductListToJson(productList);
        event["Orders"] = convertOrderListToJson(orderList);
        writer->write(event, &file);
        Json::Value arreglo(Json::arrayValue);
        file.close();

}

Json::Value fileManagement::convertClientListToJson(std::shared_ptr<List<Client>> clientList) {
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
    return arreglo;

}

Json::Value fileManagement::convertExtrasToJson(std::shared_ptr<List<Extras>> extraList) {
    Json::Value arreglo(Json::arrayValue);
    std::shared_ptr<Nodo<Extras>> tempExtras = extraList->getFirst();
    while (extraList != nullptr) {
        Json::Value extras;
        extras["Name"] = tempExtras->getElement()->getName();
        extras["Price"] = tempExtras->getElement()->getPrice();
        arreglo.append(extras);
        tempExtras = tempExtras->getNext();
    }
    return arreglo;

}


Json::Value fileManagement::convertProductListToJson(std::shared_ptr<List<Product>> productList) {
    Json::Value arreglo(Json::arrayValue);
    std::shared_ptr<Nodo<Product>> tempProducts = productList->getFirst();
    while (tempProducts != nullptr) {
        Json::Value product;
        product["Name"] = tempProducts->getElement()->getName();
        product["Price"] = tempProducts->getElement()->getPrice();
        if (tempProducts->getElement()->getExtras() != nullptr && !tempProducts->getElement()->getExtras()->isEmpty()) {
            product["Extras"] = convertExtrasToJson(tempProducts->getElement()->getExtras());
        }
        arreglo.append(product);
        tempProducts = tempProducts->getNext();
    }
    return arreglo;

}

Json::Value fileManagement::convertOrderListToJson(std::shared_ptr<List<Order>> orderList) {
    Json::Value arreglo(Json::arrayValue);
    std::shared_ptr<Nodo<Order>> tempOrder = orderList->getFirst();
    while (orderList != nullptr) {
        Json::Value order;
        order["Order"] = tempOrder->getElement()->getOrderID();
        order["Client name"] = tempOrder->getElement()->getClientsName();
        order["Total price"] = tempOrder->getElement()->getTotalPrice();
        order["Products"] = convertProductListToJson(tempOrder->getElement()->getProductsList());
        if (tempOrder->getElement()->getPaymentMethod() != nullptr) {
            if (dynamic_cast<Card*>(tempOrder->getElement()->getPaymentMethod().get()) != nullptr) {
                order["Payment method"] = "Card";
            } else if (dynamic_cast<Cash*>(tempOrder->getElement()->getPaymentMethod().get()) != nullptr) {
                order["Payment method"] = "Cash";
            } else if (dynamic_cast<Digital*>(tempOrder->getElement()->getPaymentMethod().get()) != nullptr) {
                order["Payment method"] = "Digital";
            }
        }

        arreglo.append(order);
        tempOrder = tempOrder->getNext();
    }
    return arreglo;
}




/*
std::string fileManagement::loadFromFile(std::shared_ptr<List<Client>> &clientList,
                                  std::shared_ptr<List<Product>> &productList, std::shared_ptr<List<Order>> &orderList) {




}
*/

/*
Json::Value fileManagement::loadClientListToJson(const Json::Value& root, std::shared_ptr<List<Client>> &clientList) {


    Json::Value Clients = root["Clients"];
    Json::ArrayIndex i = 0;
    while (i <  Clients.size()) {
        const Json::Value& item = Clients[i];
        std::string name = item["Name"].asString();
        std::string id = item["ID"].asString();
        std::string price = item["Phone"].asString();
        std::shared_ptr<Client> client = std::make_shared<Client>(name, id, price);
        clientList->insertFirst(client);
    }
}
*/




