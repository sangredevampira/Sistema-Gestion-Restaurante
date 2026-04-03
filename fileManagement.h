//
// Created by derek on 01/04/2026.
//

#ifndef PROYECTO_1_KRIS_Y_DEREK_FILEMANAGEMENT_H
#define PROYECTO_1_KRIS_Y_DEREK_FILEMANAGEMENT_H

#include "Utilities/Utilities.h"
#include "Entities headers/Order.h"
#include "Entities headers/Client.h"
#include "Decorator Headers/Product.h"
#include "ListEntitie/List.h"
#include "dist/json/json.h"
#include "Decorator Headers/Extras.h"
#include "Entities headers/Card.h"
#include "Entities headers/Cash.h"
#include "Entities headers/Digital.h"

class fileManagement {
public:
    //metodos para limpiar lista
    void clearClienteList(std::shared_ptr<List<Client>>&clientList);
    void clearProductList(std::shared_ptr<List<Product>>&productList);
    void clearOrderList(std::shared_ptr<List<Order>>&orderList);

    //metodos de guardar archivos Json
    std::string saveToFile(std::shared_ptr<List<Client>> clientList, std::shared_ptr<List<Product>> productList, std::shared_ptr<List<Order>> orderList);
    Json::Value convertClientListToJson(std::shared_ptr<List<Client>> clientList);
    Json::Value convertProductListToJson(std::shared_ptr<List<Product>> productList);
    Json::Value convertOrderListToJson(std::shared_ptr<List<Order>> orderList);
    Json::Value convertExtrasToJson(std::shared_ptr<List<Extras>> extraList);

    //metodos de leer archivos Json

    void loadFromFile(std::shared_ptr<List<Client>>&clientList, std::shared_ptr<List<Product>>&productList, std::shared_ptr<List<Order>>&orderList);
    void loadClientListToJson(const Json::Value& root, std::shared_ptr<List<Client>>&clientList);
    void loadProductListToJson(const Json::Value& root, std::shared_ptr<List<Product>>&productList);
    void loadOrderListToJson(const Json::Value& root, std::shared_ptr<List<Order>>&orderList);
    void loadExtrasListToJson(const Json::Value& root, std::shared_ptr<List<Extras>>&extraList, std::string type);


};


#endif //PROYECTO_1_KRIS_Y_DEREK_FILEMANAGEMENT_H