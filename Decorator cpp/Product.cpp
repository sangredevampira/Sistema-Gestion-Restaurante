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
std::ostream & operator<<(std::ostream &os, const std::shared_ptr<Product> baseProduct) {
    os << "Nombre: " << baseProduct->name << std::endl;
    os << "Precio: " << baseProduct->price << " colones" << std::endl;
    int n = 1;

    if (baseProduct->extras != nullptr && !baseProduct->extras->isEmpty()) {
        os << "Extras:" << std::endl;

        std::shared_ptr<Nodo<Extras>> current = baseProduct->extras->getFirst();
        while (current != nullptr) {
            std::shared_ptr<Extras> e = current->getElement();
            if (e != nullptr) {
                os << "  " << n << ". " << e->getName() << " (+" << e->getPrice() << " colones)" << std::endl;
            }
            current = current->getNext();
            n++;

        }
        os << "Precio incluyendo los extras: " << baseProduct->price + baseProduct->calculatePriceExtras() << " colones" << std::endl;
    }

    return os;
}

std::shared_ptr<Extras> Product::searchExtraByIndex(int index)
{
    bool found = false;
    std::shared_ptr<Nodo<Extras>> currentNode = extras->getFirst();
    std::shared_ptr<Extras> searched = nullptr;
    for (int i = 1; i <= extras->length() && !found; i++)
    {
        if (i == index)
        {
            found = true;
            searched = currentNode->getElement();
        }else
            currentNode = currentNode->getNext();

    }
    return searched;
}

std::string Product::addExtraToProduct(std::shared_ptr<Extras> extras) {
    if (extras == nullptr) {
        return "No se puede agregar un extra nulo al producto";
    }
    this->extras->insertFirst(extras);
    return "Extra agregado: " + extras->getName() + " al producto";
}


std::string Product::removeExtraFromProduct(std::string extrasName) {
    if (extras == nullptr || extras->isEmpty()) {
        return "No hay extras para eliminar en el producto";
    }

    std::shared_ptr<Nodo<Extras>> currentNode = extras->getFirst();
    std::shared_ptr<Extras> targetExtra;

    while (currentNode != nullptr) {
        std::shared_ptr<Extras> elem = currentNode->getElement();
        if (elem != nullptr && elem->getName() == extrasName) {
            targetExtra = elem;
            price -= elem->getPrice();
            break;
        }
        currentNode = currentNode->getNext();
    }

    if (targetExtra == nullptr) {
        return "No se encontro el extra '" + extrasName + "' en el producto";
    }

    extras->deleteElement(targetExtra);

    return "Extra eliminado: " + extrasName + " del producto";
}

std::shared_ptr<List<Extras>> Product::getExtras() const
{
    return extras;
}

void Product::setExtras(std::shared_ptr<List<Extras>> extras)
{
    this->extras = extras;
}

float Product::calculatePriceExtras()
{
    float totalExtras = 0.0f;

    if (extras == nullptr || extras->isEmpty())
        return totalExtras;

    std::shared_ptr<Nodo<Extras>> current = extras->getFirst();

    while (current != nullptr)
    {
        std::shared_ptr<Extras> extra = current->getElement();
        if (extra != nullptr)
            totalExtras += extra->getPrice();
        current = current->getNext();
    }

    return totalExtras;
}


