//
// Created by XPC on 27/3/2026.
//

#ifndef PROYECTO_1_EXCEPTION_H
#define PROYECTO_1_EXCEPTION_H

#include <exception>
#include <iostream>

class GeneralException : public std::exception
{
protected:
    std::string message;
public:
    GeneralException(const std::string message);
    const char* what() const noexcept override;
};


#endif //PROYECTO_1_EXCEPTION_H