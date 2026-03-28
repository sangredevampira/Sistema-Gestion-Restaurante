//
// Created by derek on 25/03/2026.
//

#ifndef PRACTICA_TEMPLATES_LISTA_H
#define PRACTICA_TEMPLATES_LISTA_H


#include "Nodo.h"

template<class T>
class List {
private:
    Nodo<T>* first;
    public:
    List();
    ~List();
    void insertarInicio(T*);
    bool estaVacio();
    std::string toStringLista();

};

template<class T>
List<T>::List() {
    first = nullptr;
    std::cout<<"Se creo una lista generica."<<std::endl;

}

template<class T>
List<T>::~List() {
    Nodo<T>* temp = first;
    while (temp != nullptr) {
        Nodo<T>* aux = temp;
        temp = temp->getNext();
        delete aux;
    }
}

template<class T>
bool List<T>::estaVacio() {
    return (first == nullptr);
}

template<class T>
void List<T>::insertarInicio(T* dato) {
    first = new Nodo<T>(dato, first);
}

template<class T>
std::string List<T>::toStringLista() {
    std::stringstream s;
    Nodo<T>* temp = first;
    if (temp == nullptr) {
        s << "lista vacia.";
    }
    while (temp != nullptr) {
        s << temp->getElement()->mostrarCliente() << std::endl;
        temp = temp->getNext();
    }
    return s.str();
}


#endif //PRACTICA_TEMPLATES_LISTA_H