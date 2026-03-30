//
// Created by derek on 25/03/2026.
//

#ifndef PRACTICA_TEMPLATES_LISTA_H
#define PRACTICA_TEMPLATES_LISTA_H


#include "Nodo.h"

template<class T>
class List {
private:
    std::shared_ptr<Nodo<T>> first;
    public:
    List();
    void insertFirst(std::shared_ptr<T>);
    bool isEmpty();
    std::shared_ptr<Nodo<T>> getFirst();

};

template<class T>
List<T>::List() {
    first = nullptr;
    std::cout<<"Se creo una lista generica."<<std::endl;

}

template<class T>
bool List<T>::isEmpty() {
    return (first == nullptr);
}

template<class T>
void List<T>::insertFirst(std::shared_ptr<T> dato) {
    first = new Nodo<T>(dato, first);
}


template<class T>
std::shared_ptr<Nodo<T>> List<T>::getFirst() {
    return first;
}


#endif //PRACTICA_TEMPLATES_LISTA_H
