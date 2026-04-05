//
// Created by XPC on 29/3/2026.
//

#ifndef PROYECTO_1_CLIENTMANAGER_H
#define PROYECTO_1_CLIENTMANAGER_H

#include "Client.h"
#include "../ListEntitie/List.h"

class ClientManagement
{
private:
    std::shared_ptr<List<Client>> clientsList;
public:
    ClientManagement();
    std::string addClient(std::string, std::string, std::string);
    std::shared_ptr<Client> searchClient(std::string);
    std::shared_ptr<List<Client>> getClientList();
    //void loadClients();
};


#endif //PROYECTO_1_CLIENTMANAGER_H