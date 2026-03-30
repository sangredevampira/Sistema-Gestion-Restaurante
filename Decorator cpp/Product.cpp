//
// Created by derek on 28/03/2026.
//

#include "../Decorator Headers/Product.h"
#include "../Decorator Headers/Extras.h"

Product::Product(std::string name, float price) {
    this->name = name;
    this->price = price;
    extras = std::make_shared<List<Extras>>();
}
std::ostream & operator<<(std::ostream &os, const Product *baseProduct) {
    os << "Nombre: "<< baseProduct->name << std::endl;
    os << "Precio: " << baseProduct->price << std::endl;
    return os;
}

std::string Product::addExtraToProduct(std::shared_ptr<Product> baseProduct, std::shared_ptr<Extras> extras) {
    if (extras == nullptr) {
        return "No se puede agregar un extra nulo al producto: " + baseProduct->getName();
    }
    this->extras->insertFirst(extras);
    return "Extra agregado: " + extras->description() + " al producto: " + baseProduct->getName();
}


std::string Product::removeExtraFromProduct(std::shared_ptr<Product> baseProduct,
                                            std::string extrasName) {
    if (extras == nullptr || extras->isEmpty()) {
        return "No hay extras para eliminar en el producto: " + baseProduct->getName();
    }

    std::shared_ptr<Nodo<Extras>> currentNode = extras->getFirst();
    std::shared_ptr<Extras> targetExtra;

    while (currentNode != nullptr) {
        std::shared_ptr<Extras> elem = currentNode->getElement();
        if (elem != nullptr && elem->getName() == extrasName) {
            targetExtra = elem;
            break;
        }
        currentNode = currentNode->getNext();
    }

    if (targetExtra == nullptr) {
        return "No se encontro el extra '" + extrasName + "' en el producto: " + baseProduct->getName();
    }

    extras->deleteElement(targetExtra);

    return "Extra eliminado: " + extrasName + " del producto: " + baseProduct->getName();
}