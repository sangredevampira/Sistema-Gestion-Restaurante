//
// Created by XPC on 27/3/2026.
//

#include "GeneralException.h"


GeneralException::GeneralException(const std::string message)
    : message(message){}

const char* GeneralException::what() const noexcept
{
    return message.c_str();
}
