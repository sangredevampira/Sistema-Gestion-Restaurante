//
// Created by derek on 24/03/2026.
//

#include "../Entities headers/Client.h"

Client::Client(std::string name, std::string id, std::string phone) {
    this->name = name;
    this->id = id;
    this->phone = phone;
}

Client::~Client() {
}

std::string Client::getName() {
    return name;
}

std::string Client::getPhone() {
    return phone;
}

std::string Client::getId() {
    return id;
}

void Client::setName(std::string name) {
    this->name = name;
}

void Client::setPhone(std::string phone) {
    this->phone = phone;
}

void Client::setId(std::string id) {
    this->id = id;
}

std::string Client::mostrarCliente() {
    std::stringstream s;
    s << "Nombre: " << name << std::endl;
    s << "ID: " << id << std::endl;
    s << "Telefono: " << phone << std::endl;
    return s.str();
}

