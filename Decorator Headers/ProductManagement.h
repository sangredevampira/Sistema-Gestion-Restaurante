//
// Created by derek on 30/03/2026.
//

#ifndef PROYECTO_1_KRIS_Y_DEREK_PRODUCTMANAGEMENT_H
#define PROYECTO_1_KRIS_Y_DEREK_PRODUCTMANAGEMENT_H

#include "../ListEntitie/List.h"
#include "../Utilities/Utilities.h"
#include "Product.h"
class ProductManagement {
private:
    std::shared_ptr<List<Product>> productList;
public:
    ProductManagement( std::shared_ptr<List<Product>> productList);
    std::string addProduct(std::shared_ptr<Product> product);
    std::shared_ptr<Product> searchProduct(std::string name);
    std::string showProduct(std::shared_ptr<Product> product);


};


#endif //PROYECTO_1_KRIS_Y_DEREK_PRODUCTMANAGEMENT_H