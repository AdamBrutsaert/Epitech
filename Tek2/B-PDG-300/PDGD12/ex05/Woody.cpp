/*
** EPITECH PROJECT, 2024
** Woody.cpp
** File description:
** Woody.cpp
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name)
    : Toy(Toy::WOODY, name, "woody.txt")
{
}

Woody::Woody(const std::string &name, const std::string &file)
    : Toy(Toy::WOODY, name, file)
{
}

void Woody::speak(const std::string &statement)
{
    std::cout << "WOODY: ";
    Toy::speak(statement);
}
