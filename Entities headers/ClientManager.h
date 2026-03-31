//
// Created by XPC on 29/3/2026.
//

#ifndef PROYECTO_1_CLIENTMANAGER_H
#define PROYECTO_1_CLIENTMANAGER_H

#include "Client.h"
#include "../ListEntitie/List.h"

class ClientManager
{
private:
    std::shared_ptr<List<Client>> clientsList;
public:
    ClientManager();
    std::string addClient(std::string, std::string, std::string);
    bool searchClient(std::string);
};


#endif //PROYECTO_1_CLIENTMANAGER_H