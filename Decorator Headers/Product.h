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
    std::shared_ptr<List<Extras>> extras;
    public:
    Product(std::string name = "", float price = 0.0);
    virtual ~Product() = default;
    virtual std::string getName() = 0;
    virtual float getPrice() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Product* baseProduct); // operador sobrecargado
    std::shared_ptr<Extras> searchExtraByIndex(int index);
    std::string addExtraToProduct(std::shared_ptr<Extras> extras);
    std::string removeExtraFromProduct(std::string extra);
    std::shared_ptr<List<Extras>> getExtras() const;
    void setExtras(std::shared_ptr<List<Extras>> extras);

    virtual std::shared_ptr<Product> clone() const = 0;


};


#endif //PROYECTO_1_PROGA_2_DEREK_Y_KRIS_PRODUCT_H