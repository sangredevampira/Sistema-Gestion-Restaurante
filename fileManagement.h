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

class fileManagement {
public:
   bool saveToFile(std::shared_ptr<List<Client>> clientList, std::shared_ptr<List<Product>> productList, std::shared_ptr<List<Order>> orderList);
   bool loadFromFile(std::shared_ptr<List<Client>>&clientList, std::shared_ptr<List<Product>>&productList, std::shared_ptr<List<Order>>&orderList);


};


#endif //PROYECTO_1_KRIS_Y_DEREK_FILEMANAGEMENT_H