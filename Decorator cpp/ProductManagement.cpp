//
// Created by derek on 30/03/2026.
//

#include "../Decorator Headers/ProductManagement.h"


ProductManagement::ProductManagement() {
    this->productList = std::make_shared<List<Product>>();
}

std::string ProductManagement::addProduct(std::shared_ptr<Product> product) {
    if (product == nullptr) {
        return "No se puede agregar un producto nulo.";
    }

    // Asegurar que la lista exista
    if (productList == nullptr) {
        productList = std::make_shared<List<Product>>();
    }

    // Evitar productos duplicados por nombre
    std::shared_ptr<Nodo<Product>> current = productList->getFirst();
    while (current != nullptr) {
        if (current->getElement() != nullptr &&
            current->getElement()->getName() == product->getName()) {
            return "Ya existe un producto con ese nombre: " + product->getName();
            }
        current = current->getNext();
    }

    // Insertar en la lista
    productList->insertFirst(product);

    std::stringstream ss;
    ss << "Producto agregado: " << product->getName()
       << " (" << product->getPrice() << ")";
    return ss.str();
}

std::shared_ptr<Product> ProductManagement::searchProduct(std::string name) {
    // Si no hay lista o está vacía, no hay nada que buscar
    if (productList == nullptr || productList->isEmpty()) {
        return nullptr;
    }

    std::shared_ptr<Nodo<Product>> current = productList->getFirst();
    while (current != nullptr) {
        std::shared_ptr<Product> elem = current->getElement();
        if (elem != nullptr && elem->getName() == name) {
            return elem; // Producto encontrado
        }
        current = current->getNext();
    }

    // No se encontró ningún producto con ese nombre
    return nullptr;
}

std::string ProductManagement::showProduct(std::shared_ptr<Product> product) {
    if (product == nullptr) {
        return "Producto nulo";
    }

    std::stringstream ss;
    // Usa tu operador << sobrecargado que recibe Product*
    ss << product.get();

    return ss.str();
}

std::shared_ptr<List<Product>> ProductManagement::getProductList() {
    return productList;
}

