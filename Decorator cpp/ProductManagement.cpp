//
// Created by derek on 30/03/2026.
//

#include "../Decorator Headers/ProductManagement.h"


ProductManagement::ProductManagement() {
    this->productList = std::make_shared<List<Product>>();
    this->extrasList = std::make_shared<List<Extras>>();
    loadProducts();
    loadExtras();
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

std::shared_ptr<Product> ProductManagement::searchProduct(int index)
{
    if (productList == nullptr || productList->isEmpty()) {
        return nullptr;
    }
    bool found = false;
    std::shared_ptr<Nodo<Product>> current = productList->getFirst();
    for (int i = 1; i <= productList->length() && !found; i++)
    {
        if (i == index)
        {
            found = true;
            return current->getElement();
        }else current = current->getNext();
    }
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

std::shared_ptr<List<Extras>> ProductManagement::getExtrasList()
{ return extrasList; }

std::string ProductManagement::showExtrasByType(std::shared_ptr<Product> product)
{
    int type;
    if (dynamic_cast<Meal*>(product.get()) != nullptr) type = 1;
    if (dynamic_cast<Beverage*>(product.get()) != nullptr) type = 2;
    if (dynamic_cast<Dessert*>(product.get()) != nullptr) type = 3;

    std::stringstream ss;
    std::shared_ptr<Nodo<Extras>> current = extrasList->getFirst();
    for (int i = 1; i <= extrasList->length(); i++)
    {
        if (type == 1)
            if (dynamic_cast<MealExtra*>(current->getElement().get()))
                ss << i << ". " << current->getElement() << "\n";
        if (type == 2)
            if (dynamic_cast<ExtraBeverage*>(current->getElement().get()))
                ss << i << ". " << current->getElement() << "\n";
        if (type == 3)
            if (dynamic_cast<ExtraDessert*>(current->getElement().get()))
                ss << i << ". " << current->getElement() << "\n";
        current = current->getNext();
    }

    return ss.str();
}

std::shared_ptr<Extras> ProductManagement::searchExtra(int index)
{
    if (productList == nullptr || productList->isEmpty()) {
        return nullptr;
    }
    bool found = false;
    std::shared_ptr<Nodo<Extras>> current = extrasList->getFirst();
    for (int i = 1; i <= extrasList->length() && !found; i++)
    {
        if (i == index)
        {
            found = true;
            return current->getElement();
        }else current = current->getNext();
    }
    return nullptr;
}

void ProductManagement::loadProducts()
{
    productList->insertFirst(std::make_shared<Meal>("Hamburguesa", 1500));
    productList->insertFirst(std::make_shared<Meal>("Pizza", 2000));
    productList->insertFirst(std::make_shared<Meal>("Perro Caliente", 1000));
    productList->insertFirst(std::make_shared<Meal>("Pasta", 3500));
    productList->insertFirst(std::make_shared<Meal>("Burrito", 1200));

    productList->insertFirst(std::make_shared<Beverage>("Coca-Cola", 800));
    productList->insertFirst(std::make_shared<Beverage>("Fanta", 800));
    productList->insertFirst(std::make_shared<Beverage>("Sprite", 800));
    productList->insertFirst(std::make_shared<Beverage>("Agua", 500));
    productList->insertFirst(std::make_shared<Beverage>("GingerAle", 800));

    productList->insertFirst(std::make_shared<Dessert>("Helado", 700));
    productList->insertFirst(std::make_shared<Dessert>("Pastel", 1200));
    productList->insertFirst(std::make_shared<Dessert>("Galleta", 500));
    productList->insertFirst(std::make_shared<Dessert>("Brownie", 900));
    productList->insertFirst(std::make_shared<Dessert>("Flan", 600));

}

void ProductManagement::loadExtras()
{
    extrasList->insertFirst(std::make_shared<MealExtra>("Doble carne", 500));
    extrasList->insertFirst(std::make_shared<MealExtra>("Queso extra", 200));
    extrasList->insertFirst(std::make_shared<MealExtra>("Tocino extra", 300));


    extrasList->insertFirst(std::make_shared<ExtraBeverage>("Hielo extra", 50));
    extrasList->insertFirst(std::make_shared<ExtraBeverage>("Limón extra", 30));
    extrasList->insertFirst(std::make_shared<ExtraBeverage>("Soda extra", 50));


    extrasList->insertFirst(std::make_shared<ExtraDessert>("Chocolate extra", 100));
    extrasList->insertFirst(std::make_shared<ExtraDessert>("Frutas extra", 150));
    extrasList->insertFirst(std::make_shared<ExtraDessert>("Nueces Extra" , 200));


}

