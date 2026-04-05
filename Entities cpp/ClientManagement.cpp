//
// Created by XPC on 29/3/2026.
//

#include "../Entities headers/ClientManagement.h"

ClientManagement::ClientManagement() {
    clientsList = std::make_shared<List<Client>>();
    loadClients();
}

std::string ClientManagement::addClient(std::string name, std::string id, std::string phoneNumber)
{
    std::string message;
    if (searchClient(id) == nullptr)
    {
        std::shared_ptr<Client> newClient = std::make_shared<Client>(name, id, phoneNumber);
        clientsList->insertFirst(newClient);
        message = "Cliente agregado exitosamente!\n";
    }else message = "El cliente ya existe\n";

    return message;
}

std::shared_ptr<Client> ClientManagement::searchClient(std::string name)
{
    bool found = false;
    std::shared_ptr<Client> searched = nullptr;
    std::shared_ptr<Nodo<Client>> current = clientsList->getFirst();
    while (!found && current != nullptr){
        if (current->getElement()->getName() == name)
        {
            found = true;
            searched = current->getElement();

        }else current = current->getNext();
    }
    return searched;
}

std::shared_ptr<List<Client>> ClientManagement::getClientList() {
    return clientsList;
}

void ClientManagement::loadClients()
{
    clientsList->insertFirst(std::make_shared<Client>("Kris Peraza", "101", "88881111"));
    clientsList->insertFirst(std::make_shared<Client>("Derek Garcia", "102", "88882222"));
    clientsList->insertFirst(std::make_shared<Client>("Javi Garita", "103", "88883333"));
    clientsList->insertFirst(std::make_shared<Client>("Mariana Arroyo", "104", "88884444"));
    clientsList->insertFirst(std::make_shared<Client>("Paulina Rojas", "105", "88885555"));
    clientsList->insertFirst(std::make_shared<Client>("Stiven Salas", "106", "88886666"));
    clientsList->insertFirst(std::make_shared<Client>("Adrian Fernandez", "107", "88887777"));
    clientsList->insertFirst(std::make_shared<Client>("Josue Penaranda", "108", "88888888"));
    clientsList->insertFirst(std::make_shared<Client>("Josue Rojas", "109", "88889999"));
    clientsList->insertFirst(std::make_shared<Client>("Ronny Villalobos", "110", "88880000"));
}
