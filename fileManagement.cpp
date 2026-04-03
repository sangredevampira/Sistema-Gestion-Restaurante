//
// Created by derek on 01/04/2026.
//

#include "fileManagement.h"

#include "Decorator Headers/Beverage.h"
#include "Decorator Headers/BigSize.h"
#include "Decorator Headers/Dessert.h"
#include "Decorator Headers/ExtraBeverage.h"
#include "Decorator Headers/ExtraDessert.h"
#include "Decorator Headers/Meal.h"
#include "Decorator Headers/MealExtra.h"
#include "Decorator Headers/MediumSize.h"
#include "Decorator Headers/SmallSize.h"
#include "dist/json/json.h"
#include "Exceptions/MissingFile.h"


// metodos para guardar archivod
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
        return "Archivo guardado exitosamente\n";

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
    while (tempExtras != nullptr) {
        Json::Value extras;
        extras["Name"] = tempExtras->getElement()->getName();
        extras["Price"] = tempExtras->getElement()->getPrice();
        if (dynamic_cast<MealExtra*>(tempExtras->getElement().get()) != nullptr) {
            extras["Type"] = "Meal";
        } else if (dynamic_cast<ExtraBeverage*>(tempExtras->getElement().get()) != nullptr) {
            extras["Type"] = "Beverage";
        } else if (dynamic_cast<ExtraDessert*>(tempExtras->getElement().get()) != nullptr) {
            extras["Type"] = "Dessert";
        } else if (dynamic_cast<SmallSize*>(tempExtras->getElement().get()) != nullptr) {
            extras["Type"] = "SmallSize";
        } else if (dynamic_cast<MediumSize*>(tempExtras->getElement().get()) != nullptr) {
            extras["Type"] = "MediumSize";
        } else if (dynamic_cast<BigSize*>(tempExtras->getElement().get()) != nullptr) {
            extras["Type"] = "BigSize";
        }
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
        if (dynamic_cast<Meal*>(tempProducts->getElement().get()) != nullptr) {
            product["Type"] = "Meal";
        } else if (dynamic_cast<Beverage*>(tempProducts->getElement().get()) != nullptr) {
            product["Type"] = "Beverage";
        } else if (dynamic_cast<Dessert*>(tempProducts->getElement().get()) != nullptr) {
            product["Type"] = "Dessert";
        }
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
    while (tempOrder != nullptr) {
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

//-=--------------------------------------------------------------------------------------------------------------------------

//  metodos para leer archivos.

void fileManagement::loadFromFile(std::shared_ptr<List<Client>> &clientList,
                                  std::shared_ptr<List<Product>> &productList, std::shared_ptr<List<Order>> &orderList) {

    std::ifstream file("GestionRestaurante.txt");
    if (!file) throw  MissingFile();
    Json::Value object;
    Json::Reader reader;
    reader.parse(file, object);
    loadClientListToJson(object, clientList);
    loadProductListToJson(object, productList);
    loadOrderListToJson(object, orderList);
    reader.parse(file, object);
    file.close();
}



void fileManagement::loadClientListToJson(const Json::Value& object, std::shared_ptr<List<Client>> &clientList) {

    std::shared_ptr<Client> tempClient = std::make_shared<Client>();
    for (int i = 0; i < object.size() ; i++) {
        tempClient->setName(object["Clients"][i]["Name"].asString());
        tempClient->setId(object["Clients"][i]["ID"].asString());
        tempClient->setPhone(object["Clients"][i]["Phone"].asString());
        clientList->insertFirst(tempClient);
    }

}

void fileManagement::loadProductListToJson(const Json::Value &object, std::shared_ptr<List<Product>> &productList) {

    for (int i = 0; i < object.size() ; i++) {
        std::string type = object["Products"][i]["Type"].asString();
        std::shared_ptr<Product> tempProduct;
        if (type == "Meal") {
            tempProduct = std::make_shared<Meal>(object["Products"][i]["Name"].asString(), object["Products"][i]["Price"].asFloat());
        } else if (type == "Beverage") {
            tempProduct = std::make_shared<Beverage>(object["Products"][i]["Name"].asString(), object["Products"][i]["Price"].asFloat());
        } else if (type == "Dessert") {
            tempProduct = std::make_shared<Dessert>(object["Products"][i]["Name"].asString(), object["Products"][i]["Price"].asFloat());
        }
        if (object["Products"][i].isMember("Extras")) {
            std::shared_ptr<List<Extras>> extraList = std::make_shared<List<Extras>>();
            loadExtrasListToJson(object["Products"][i], extraList, type, tempProduct);
            tempProduct->getExtras() = extraList;
        }
        productList->insertFirst(tempProduct);
    }
}



void fileManagement::loadOrderListToJson(const Json::Value &object, std::shared_ptr<List<Order>> &orderList) {
    std::shared_ptr<Order> order;
    for (int i = 0; i < object.size() ; i++) {
        int orderID = object["Order"][i]["ID"].asInt();
        std::string clientsName = object["Order"][i]["ClientName"].asString();
        std::shared_ptr<List<Product>> productsList = std::make_shared<List<Product>>();
        loadProductListToJson(object["Order"][i]["Products"], productsList);
        std::shared_ptr<PaymentMethod> payment;
        if (object["Order"][i]["PaymentMethod"].asString() == "Card") {
            payment = std::make_shared<Card>();
        } else if (object["Order"][i]["PaymentMethod"].asString() == "Cash") {
            payment = std::make_shared<Cash>();
        } else if (object["Order"][i]["PaymentMethod"].asString() == "Digital") {
            payment = std::make_shared<Digital>();
        }
        float totalPrice = object["Order"][i]["Price"].asFloat();
        order = std::make_shared<Order>(orderID, clientsName, productsList, payment, totalPrice);
        orderList->insertFirst(order);
    }
}

void fileManagement::loadExtrasListToJson(const Json::Value &object, std::shared_ptr<List<Extras>> &extraList, std::string type, std::shared_ptr<Product> product) {
    for (int i = 0; i < object.size() ; i++) {
        std::shared_ptr<Extras> tempExtras;
        std::string name = object["Extras"][i]["Name"].asString();
        float price = object["Extras"][i]["Price"].asFloat();
        if (type == "Meal") {
            tempExtras = std::make_shared<MealExtra>(product, name, price);
        } else if (type == "Beverage") {
            tempExtras = std::make_shared<ExtraBeverage>(product, name, price);
        } else if (type == "Dessert") {
            tempExtras = std::make_shared<ExtraDessert>(product, name, price);
        } else if (type == "SmallSize") {
            tempExtras = std::make_shared<SmallSize>(product, name, price);
        } else if (type == "MediumSize") {
            tempExtras = std::make_shared<MediumSize>(product, name, price);
        } else if (type == "BigSize") {
            tempExtras = std::make_shared<BigSize>(product, name, price);
         }
         extraList->insertFirst(tempExtras);
    }


}



