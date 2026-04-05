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

    if (productList == nullptr) {
        productList = std::make_shared<List<Product>>();
    }

    std::shared_ptr<Nodo<Product>> current = productList->getFirst();
    while (current != nullptr) {
        if (current->getElement() != nullptr &&
            current->getElement()->getName() == product->getName()) {
            return "Ya existe un producto con ese nombre: " + product->getName();
            }
        current = current->getNext();
    }

    productList->insertFirst(product);

    std::stringstream ss;
    ss << "Producto agregado: " << product->getName()
       << " (" << product->getPrice() << ")";
    return ss.str();
}

std::shared_ptr<Product> ProductManagement::searchProduct(std::string name) {
    if (productList == nullptr || productList->isEmpty()) {
        return nullptr;
    }

    std::shared_ptr<Nodo<Product>> current = productList->getFirst();
    while (current != nullptr) {
        std::shared_ptr<Product> elem = current->getElement();
        if (elem != nullptr && elem->getName() == name) {
            return elem;
        }
        current = current->getNext();
    }

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
    ss << product.get();

    return ss.str();
}

std::shared_ptr<List<Product>> ProductManagement::getProductList() {
    return productList;
}

std::shared_ptr<List<Extras>> ProductManagement::getExtrasList()
{ return extrasList; }

int ProductManagement::countExtrasByType(std::shared_ptr<Product> product)
{
    int type;
    if (dynamic_cast<Meal*>(product.get()) != nullptr) type = 1;
    if (dynamic_cast<Beverage*>(product.get()) != nullptr) type = 2;
    if (dynamic_cast<Dessert*>(product.get()) != nullptr) type = 3;

    int count = 0;
    std::shared_ptr<Nodo<Extras>> current = extrasList->getFirst();

    for (int i = 1; i <= extrasList->length(); i++)
    {
        if (type == 1)
            if (dynamic_cast<MealExtra*>(current->getElement().get()))
                count++;

        if (type == 2)
            if (dynamic_cast<ExtraBeverage*>(current->getElement().get()))
                count++;

        if (type == 3)
            if (dynamic_cast<ExtraDessert*>(current->getElement().get()))
                count++;

        current = current->getNext();
    }

    return count;
}

std::string ProductManagement::showExtrasByType(std::shared_ptr<Product> product)
{
    int type;
    if (dynamic_cast<Meal*>(product.get()) != nullptr) type = 1;
    if (dynamic_cast<Beverage*>(product.get()) != nullptr) type = 2;
    if (dynamic_cast<Dessert*>(product.get()) != nullptr) type = 3;

    std::stringstream ss;
    std::shared_ptr<Nodo<Extras>> current = extrasList->getFirst();

    int displayIndex = 1;

    for (int i = 1; i <= extrasList->length(); i++)
    {
        if (type == 1)
            if (dynamic_cast<MealExtra*>(current->getElement().get()))
            {
                ss << displayIndex << ". " << current->getElement() << "\n";
                displayIndex++;
            }

        if (type == 2)
            if (dynamic_cast<ExtraBeverage*>(current->getElement().get()))
            {
                ss << displayIndex << ". " << current->getElement() << "\n";
                displayIndex++;
            }

        if (type == 3)
            if (dynamic_cast<ExtraDessert*>(current->getElement().get()))
            {
                ss << displayIndex << ". " << current->getElement() << "\n";
                displayIndex++;
            }

        current = current->getNext();
    }

    return ss.str();
}

std::shared_ptr<Extras> ProductManagement::classifySize(int index)
{

    std::shared_ptr<Extras> selected = nullptr;
    std::shared_ptr<Nodo<Extras>> current = extrasList->getFirst();
    bool found = false;

    for (int i = 1; i <= extrasList->length() && !found; i++)
    {
        if (index == 1)
        {
            if (dynamic_cast<BigSize*>(current->getElement().get()))
            {
                selected = current->getElement();
                found = true;
            }
        }

        if (index == 2)
        {
            if (dynamic_cast<MediumSize*>(current->getElement().get()))
            {
                selected = current->getElement();
                found = true;
            }
        }

        if (index == 3)
        {
            if (dynamic_cast<SmallSize*>(current->getElement().get()))
            {
                selected = current->getElement();
                found = true;
            }
        }

        current = current->getNext();
    }

    return selected;
}

std::shared_ptr<Extras> ProductManagement::searchExtra(int index, std::shared_ptr<Product> product)
{
    if (extrasList == nullptr || extrasList->isEmpty()) {
        return nullptr;
    }

    int type;
    if (dynamic_cast<Meal*>(product.get()) != nullptr) type = 1;
    if (dynamic_cast<Beverage*>(product.get()) != nullptr) type = 2;
    if (dynamic_cast<Dessert*>(product.get()) != nullptr) type = 3;

    std::shared_ptr<Nodo<Extras>> current = extrasList->getFirst();
    int displayIndex = 1;

    for (int i = 1; i <= extrasList->length(); i++)
    {
        auto extra = current->getElement();

        if (type == 1)
        {
            if (dynamic_cast<MealExtra*>(extra.get()))
            {
                if (displayIndex == index)
                    return extra;
                displayIndex++;
            }
        }

        if (type == 2)
        {
            if (dynamic_cast<ExtraBeverage*>(extra.get()))
            {
                if (displayIndex == index)
                    return extra;
                displayIndex++;
            }
        }

        if (type == 3)
        {
            if (dynamic_cast<ExtraDessert*>(extra.get()))
            {
                if (displayIndex == index)
                    return extra;
                displayIndex++;
            }
        }

        current = current->getNext();
    }

    return nullptr;
}

void ProductManagement::loadProducts()
{
    productList->insertFirst(std::make_shared<Meal>("Hamburguesa clasica", 1500));
    productList->insertFirst(std::make_shared<Meal>("Pizza", 3500));
    productList->insertFirst(std::make_shared<Meal>("Perro caliente", 1000));
    productList->insertFirst(std::make_shared<Meal>("Papas fritas", 1350));
    productList->insertFirst(std::make_shared<Meal>("Burrito", 1200));

    productList->insertFirst(std::make_shared<Beverage>("Coca-Cola", 800));
    productList->insertFirst(std::make_shared<Beverage>("Fanta", 800));
    productList->insertFirst(std::make_shared<Beverage>("Sprite", 800));
    productList->insertFirst(std::make_shared<Beverage>("Agua", 500));
    productList->insertFirst(std::make_shared<Beverage>("GingerAle", 800));

    productList->insertFirst(std::make_shared<Dessert>("Helado de chocolate", 1200));
    productList->insertFirst(std::make_shared<Dessert>("Pastel de chocolate", 2000));
    productList->insertFirst(std::make_shared<Dessert>("Galleta de chocolate", 800));
    productList->insertFirst(std::make_shared<Dessert>("Brownie de chocolate", 1300));
    productList->insertFirst(std::make_shared<Dessert>("Flan de coco", 1100));

}

void ProductManagement::loadExtras()
{
    extrasList->insertFirst(std::make_shared<MealExtra>("Doble carne", 700));
    extrasList->insertFirst(std::make_shared<MealExtra>("Queso extra", 300));
    extrasList->insertFirst(std::make_shared<MealExtra>("Tocino extra", 500));

    extrasList->insertFirst(std::make_shared<ExtraBeverage>("Hielo extra", 50));
    extrasList->insertFirst(std::make_shared<ExtraBeverage>("Vaso escarchado", 100));
    extrasList->insertFirst(std::make_shared<ExtraBeverage>("Zero azucar", 200));

    extrasList->insertFirst(std::make_shared<ExtraDessert>("Chocolate extra", 250));
    extrasList->insertFirst(std::make_shared<ExtraDessert>("Frutas extra", 300));
    extrasList->insertFirst(std::make_shared<ExtraDessert>("Nueces Extra" , 350));

    extrasList->insertFirst(std::make_shared<BigSize>("Tamanio grande", 900));
    extrasList->insertFirst(std::make_shared<MediumSize>("Tamanio mediano", 750));
    extrasList->insertFirst(std::make_shared<SmallSize>("Tamanio pequenio", 550));

}

