//
// Created by XPC on 31/3/2026.
//

#ifndef PROYECTO_1_EMPYORDER_H
#define PROYECTO_1_EMPYORDER_H

#include "GeneralException.h"

class EmptyOrder : public GeneralException
{
public:
    EmptyOrder();
};


#endif //PROYECTO_1_EMPYORDER_H