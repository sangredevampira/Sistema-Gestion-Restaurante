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

   std::string saveToFile(std::shared_ptr<List<Client>> clientList, std::shared_ptr<List<Product>> productList, std::shared_ptr<List<Order>> orderList);
   //std::string loadFromFile(std::shared_ptr<List<Client>>&clientList, std::shared_ptr<List<Product>>&productList, std::shared_ptr<List<Order>>&orderList);
   Json::Value convertClientListToJson(std::shared_ptr<List<Client>> clientList);
   Json::Value convertProductListToJson(std::shared_ptr<List<Product>> productList);
   Json::Value convertOrderListToJson(std::shared_ptr<List<Order>> orderList);
   Json::Value convertExtrasToJson(std::shared_ptr<List<Extras>> extraList);
   //Json::Value loadClientListToJson(const Json::Value& root, std::shared_ptr<List<Client>>&clientList);
   //Json::Value loadProductListToJson(const Json::Value& root, std::shared_ptr<List<Product>>&productList);
  // Json::Value loadOrderListToJson(const Json::Value& root, std::shared_ptr<List<Order>>&orderList);
   //Json::Value loadExtrasListToJson(const Json::Value& root, std::shared_ptr<List<Extras>>&extraList);


};


#endif //PROYECTO_1_KRIS_Y_DEREK_FILEMANAGEMENT_H