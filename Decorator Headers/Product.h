//
// Created by derek on 27/03/2026.
//

#ifndef PROYECTO_1_PROGA_2_DEREK_Y_KRIS_PRODUCT_H
#define PROYECTO_1_PROGA_2_DEREK_Y_KRIS_PRODUCT_H

#include "../Utilities/Utilities.h"
#include "../ListEntitie/List.h"
class Extras;

class Product {
protected:
    std::string name;
    float price;
    List<Extras>* extras;
    public:
    Product(std::string name = "", float price = 0.0);
    virtual ~Product() = default;
    virtual std::string getName() = 0;
    virtual float getPrice() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Product* baseProduct); // operador sobrecargado
    std::string addExtraToProduct(Product* baseProduct, Extras* extras);
    std::string removeExtraFromProduct(Product* baseProduct, std:: string extrasName);


};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_PRODUCT_H