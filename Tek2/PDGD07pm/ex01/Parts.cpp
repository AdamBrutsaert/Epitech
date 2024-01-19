/*
** EPITECH PROJECT, 2024
** Parts.cpp
** File description:
** Parts.cpp
*/

#include "Parts.hpp"

#include <iostream>

Part::Part(const std::string &serial, bool functional) noexcept
    : _serial(serial), _functionnal(functional)
{
}

Arms::Arms(const std::string &serial, bool functionnal) noexcept
    : Part(serial, functionnal)
{
}

void Arms::informations() const noexcept
{
    std::cout << "\t[Parts] Arms " << this->_serial << " status : "
              << (this->_functionnal ? "OK" : "KO") << std::endl;
}

Legs::Legs(const std::string &serial, bool functionnal) noexcept
    : Part(serial, functionnal)
{
}

void Legs::informations() const noexcept
{
    std::cout << "\t[Parts] Legs " << this->_serial << " status : "
              << (this->_functionnal ? "OK" : "KO") << std::endl;
}

Head::Head(const std::string &serial, bool functionnal) noexcept
    : Part(serial, functionnal)
{
}

void Head::informations() const noexcept
{
    std::cout << "\t[Parts] Head " << this->_serial << " status : "
              << (this->_functionnal ? "OK" : "KO") << std::endl;
}
