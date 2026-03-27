//
// Created by derek on 24/03/2026.
//

#ifndef PROYECTO_PROGRA_DEREK_Y_KRIS_CLIENTE_H
#define PROYECTO_PROGRA_DEREK_Y_KRIS_CLIENTE_H

#include "Utilities.h"

class Client {
private:
    std:: string name;
    std:: string phone;
    std:: string id;
public:
    Client(std::string name = "", std::string id = "", std:: string phone = "");
    virtual ~Client();
    std::string getName();
    std::string getPhone();
    std::string getId();
    void setName(std::string name);
    void setPhone(std::string phone);
    void setId(std::string id);
    std::string mostrarCliente();

};


#endif //PROYECTO_PROGRA_DEREK_Y_KRIS_CLIENTE_H