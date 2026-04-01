//
// Created by XPC on 31/3/2026.
//

#include "ConsoleService.h"

void ConsoleService::pause()
{
    std::cout << "\nPresiona ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void ConsoleService::clearConsole() { std::cout << std::string(10, '\n');}
