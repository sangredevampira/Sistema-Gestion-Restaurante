//
// Created by derek on 30/03/2026.
//

#ifndef PROYECTO_1_KRIS_Y_DEREK_PRODUCTMANAGEMENT_H
#define PROYECTO_1_KRIS_Y_DEREK_PRODUCTMANAGEMENT_H

#include "../ListEntitie/List.h"
#include "../Utilities/Utilities.h"
#include "Product.h"
#include "Meal.h"
#include "Beverage.h"
#include "Dessert.h"
#include "Extras.h"
#include "MealExtra.h"
#include "ExtraBeverage.h"
#include "ExtraDessert.h"
#include "BigSize.h"
#include "MediumSize.h"
#include "SmallSize.h"

class ProductManagement {
private:
    std::shared_ptr<List<Product>> productList;
    std::shared_ptr<List<Extras>> extrasList;
public:
    ProductManagement();
    std::string addProduct(std::shared_ptr<Product> product);
    std::shared_ptr<Product> searchProduct(std::string name);
    std::shared_ptr<Product> searchProduct(int index);
    std::string showProduct(std::shared_ptr<Product> product);
    std::shared_ptr<List<Product>> getProductList();


    std::shared_ptr<List<Extras>> getExtrasList();
    int countExtrasByType(std::shared_ptr<Product> product);
    std::string showExtrasByType(std::shared_ptr<Product> product);
    std::shared_ptr<Extras> classifySize(int);
    std::shared_ptr<Extras> searchExtra(int index, std::shared_ptr<Product> product);

    void loadProducts();
    void loadExtras();
};


#endif //PROYECTO_1_KRIS_Y_DEREK_PRODUCTMANAGEMENT_H