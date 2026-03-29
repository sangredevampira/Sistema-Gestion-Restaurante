//
// Created by derek on 25/03/2026.
//

#ifndef PRACTICA_TEMPLATES_NODO_H
#define PRACTICA_TEMPLATES_NODO_H

#include "Utilities.h"
template<class T>
class Nodo {
private:
  T* element;
  Nodo<T>* next;
public:
  Nodo(T* element, Nodo<T>* Next);
  Nodo<T>* getNext();
  ~Nodo();
  T* getElement();
  void setNext(Nodo<T>* sig);
  void setElement(T* element);
};

template<class T>
Nodo<T>::Nodo(T* element, Nodo<T>* next){
  this->element = element;
  this->next = next;
}


template<class T>
T* Nodo<T>::getElement() {
  return element;
}

template<class T>
Nodo<T> *Nodo<T>::getNext() {
  return next;
}

template<class T>
void Nodo<T>::setNext(Nodo<T>* next) {
  this->next = next;
}

template<class T>
void Nodo<T>::setElement(T *element) {
  this->element = element;
}

template<class T>
Nodo<T>::~Nodo() {
  delete element;
}




#endif //PRACTICA_TEMPLATES_NODO_H