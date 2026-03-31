//
// Created by XPC on 29/3/2026.
//

#include "../Entities headers/ClientManagement.h"

ClientManagement::ClientManagement()
{ clientsList = std::make_shared<List<Client>>();}

std::string ClientManagement::addClient(std::string name, std::string id, std::string phoneNumber)
{
    std::string message;
    if (!searchClient(id))
    {
        std::shared_ptr<Client> newClient = std::make_shared<Client>(name, id, phoneNumber);
        clientsList->insertFirst(newClient);
        message = "Cliente agregado exitosamente!\n";
    }else message = "El cliente ya existe\n";

    return message;
}

bool ClientManagement::searchClient(std::string id)
{
    bool found = false;
    std::shared_ptr<Nodo<Client>> current = clientsList->getFirst();
    while (!found && current != nullptr){
        if (current->getElement()->getName() == id) found = true;
        else current = current->getNext();
    }
    return found;
}

