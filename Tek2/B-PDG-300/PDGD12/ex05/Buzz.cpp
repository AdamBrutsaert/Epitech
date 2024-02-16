/*
** EPITECH PROJECT, 2024
** Buzz.cpp
** File description:
** Buzz.cpp
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name)
    : Toy(Toy::BUZZ, name, "buzz.txt")
{
}

Buzz::Buzz(const std::string &name, const std::string &file)
    : Toy(Toy::BUZZ, name, file)
{
}

void Buzz::speak(const std::string &statement)
{
    std::cout << "BUZZ: ";
    Toy::speak(statement);
}

bool Buzz::speak_es(const std::string &statement)
{
    std::cout << "BUZZ: " << this->getName() << " senorita \"" << statement << "\" senorita" << std::endl;
    return true;
}
