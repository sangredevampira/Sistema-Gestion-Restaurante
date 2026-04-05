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

//metodos para limpiar la lista

void fileManagement::clearClienteList(std::shared_ptr<List<Client>> &clientList) {
    if (clientList == nullptr) return;
    while (!clientList->isEmpty()) {
        clientList->deleteElement(clientList->getFirst()->getElement());
    }
}

void fileManagement::clearExtrasList(std::shared_ptr<List<Extras>>& extraList)
{
    if (extraList == nullptr) return;
    while (!extraList->isEmpty())
    {
        extraList->deleteElement(extraList->getFirst()->getElement());
    }
}

void fileManagement::clearProductList(std::shared_ptr<List<Product>> &productList) {
    if (productList == nullptr) return;
    while (!productList->isEmpty()) {
        productList->deleteElement(productList->getFirst()->getElement());
    }
}

void fileManagement::clearOrderList(std::shared_ptr<List<Order>> &orderList) {
    if (orderList == nullptr) return;
    while (!orderList->isEmpty()) {
        orderList->deleteElement(orderList->getFirst()->getElement());
    }
}

void clearOrderList(std::shared_ptr<List<Order>>& orderList) {
    if (orderList == nullptr) return;
    while (!orderList->isEmpty()) {
        orderList->deleteElement(orderList->getFirst()->getElement());
    }
}
//--------------------------------------------------------------------------


// metodos para guardar archivos
std::string fileManagement::saveToFile(std::shared_ptr<List<Client>> clientList, std::shared_ptr<List<Product>> productList,
                                std::shared_ptr<List<Order>> orderList, std::shared_ptr<List<Extras>> extraList) {

        Json::StreamWriterBuilder builder;
        builder["CommentStyle"] = "None";
        builder["Indentation"] = "   ";
        std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

        std:: ofstream file("GestionRestaurante.txt");
        Json::Value event;
        event["Clients"] = convertClientListToJson(clientList);
        event["Extras"] = convertExtrasToJson(extraList);
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
    Json::Value order;
    while (tempOrder != nullptr) {
        order["ID"] = tempOrder->getElement()->getOrderID();
        order["ClientName"] = tempOrder->getElement()->getClientsName();
        order["TotalPrice"] = tempOrder->getElement()->getTotalPrice();
        order["Products"] = convertProductListToJson(tempOrder->getElement()->getProductsList());
        if (tempOrder->getElement()->getPaymentMethod() != nullptr) {
            if (dynamic_cast<Card*>(tempOrder->getElement()->getPaymentMethod().get()) != nullptr) {
                order["PaymentMethod"] = "Card";
            } else if (dynamic_cast<Cash*>(tempOrder->getElement()->getPaymentMethod().get()) != nullptr) {
                order["PaymentMethod"] = "Cash";
            } else if (dynamic_cast<Digital*>(tempOrder->getElement()->getPaymentMethod().get()) != nullptr) {
                order["PaymentMethod"] = "Digital";
            }
        }

        arreglo.append(order);
        tempOrder = tempOrder->getNext();
    }

    return arreglo;
}

//------------------------------------------------------------------------------------------------------------------------------

//  metodos para leer archivos.

void fileManagement::loadFromFile(std::shared_ptr<List<Client>> &clientList,
                                  std::shared_ptr<List<Product>> &productList, std::shared_ptr<List<Order>> &orderList, int &orderRegister, std::shared_ptr<List<Extras>> extraList) {

    std::ifstream file("GestionRestaurante.txt");
    if (!file) throw MissingFile();


    clearClienteList(clientList);
    clearExtrasList(extraList);
    clearProductList(productList);
    clearOrderList(orderList);

    Json::Value object;
    Json::Reader reader;
    if (!reader.parse(file, object)) {
        throw std::runtime_error("Error al parsear el JSON de GestionRestaurante.txt");
    }

    loadClientListToJson(object, clientList);
    loadExtrasListToJson(object, extraList);
    loadProductListToJson(object, productList);
    loadOrderListToJson(object, orderList, orderRegister);

    file.close();
}



void fileManagement::loadClientListToJson(const Json::Value& object, std::shared_ptr<List<Client>> &clientList) {

    const Json::Value& clients = object["Clients"];
    for (Json::ArrayIndex i = 0; i < clients.size() ; i++) {
        std::shared_ptr<Client> tempClient = std::make_shared<Client>();
        tempClient->setName(clients[i]["Name"].asString());
        tempClient->setId(clients[i]["ID"].asString());
        tempClient->setPhone(clients[i]["Phone"].asString());
        clientList->insertFirst(tempClient);
    }

}

void fileManagement::loadProductListToJson(const Json::Value &object, std::shared_ptr<List<Product>> &productList) {

    const Json::Value& products = object.isArray() ? object : object["Products"];
    for (Json::ArrayIndex i = 0; i < products.size() ; i++) {
        std::string type = products[i]["Type"].asString();
        std::shared_ptr<Product> tempProduct;
        if (type == "Meal") {
            tempProduct = std::make_shared<Meal>(products[i]["Name"].asString(), products[i]["Price"].asFloat());
        } else if (type == "Beverage") {
            tempProduct = std::make_shared<Beverage>(products[i]["Name"].asString(), products[i]["Price"].asFloat());
        } else if (type == "Dessert") {
            tempProduct = std::make_shared<Dessert>(products[i]["Name"].asString(), products[i]["Price"].asFloat());
        }
        if (tempProduct != nullptr && products[i].isMember("Extras")) {
            std::shared_ptr<List<Extras>> extraList = std::make_shared<List<Extras>>();
            loadExtrasListToJson(products[i], extraList);
            tempProduct->getExtras() = extraList;
        }
        if (tempProduct != nullptr) {
            productList->insertLast(tempProduct);
        }
    }
}



void fileManagement::loadOrderListToJson(const Json::Value &object, std::shared_ptr<List<Order>> &orderList, int &orderRegister) {
    std::shared_ptr<Order> order;
    const Json::Value& orders = object["Orders"];
    int maxOrderId = 0;
    for (Json::ArrayIndex i = 0; i < orders.size() ; i++) {
        int orderID = orders[i]["ID"].asInt();
        if (orderID > maxOrderId) {
            maxOrderId = orderID;
        }
        std::string clientsName = orders[i]["ClientName"].asString();
        std::shared_ptr<List<Product>> productsList = std::make_shared<List<Product>>();
        loadProductListToJson(orders[i]["Products"], productsList);
        std::shared_ptr<PaymentMethod> payment;
        if (orders[i]["PaymentMethod"].asString() == "Card") {
            payment = std::make_shared<Card>();
        } else if (orders[i]["PaymentMethod"].asString() == "Cash") {
            payment = std::make_shared<Cash>();
        } else if (orders[i]["PaymentMethod"].asString() == "Digital") {
            payment = std::make_shared<Digital>();
        }
        float totalPrice = orders[i]["TotalPrice"].asFloat();
        order = std::make_shared<Order>(orderID, clientsName, productsList, payment, totalPrice);
        orderList->insertFirst(order);
    }
        orderRegister = maxOrderId + 1;
}

void fileManagement::loadExtrasListToJson(const Json::Value &object, std::shared_ptr<List<Extras>> &extraList) {
    const Json::Value& extras = object["Extras"];
    for (Json::ArrayIndex i = 0; i < extras.size() ; i++) {
        std::shared_ptr<Extras> tempExtras;
        std::string name = extras[i]["Name"].asString();
        float price = extras[i]["Price"].asFloat();
        if (extras[i]["Type"] == "Meal") {
            tempExtras = std::make_shared<MealExtra>(name, price);
        } else if (extras[i]["Type"] == "Beverage") {
            tempExtras = std::make_shared<ExtraBeverage>(name, price);
        } else if (extras[i]["Type"] == "Dessert") {
            tempExtras = std::make_shared<ExtraDessert>(name, price);
        } else if (extras[i]["Type"] == "SmallSize") {
            tempExtras = std::make_shared<SmallSize>(name, price);
        } else if (extras[i]["Type"] == "MediumSize") {
            tempExtras = std::make_shared<MediumSize>(name, price);
        } else if (extras[i]["Type"] == "BigSize") {
            tempExtras = std::make_shared<BigSize>(name, price);
         }
         extraList->insertFirst(tempExtras);
    }


}



