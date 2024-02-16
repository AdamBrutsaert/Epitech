/*
** EPITECH PROJECT, 2024
** Toy.cpp
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy()
    : _type(BASIC_TOY), _name("toy"), _picture()
{
}

Toy::Toy(ToyType type, const std::string &name, const std::string &filename)
    : _type(type), _name(name), _picture(filename)
{
}

Toy::ToyType Toy::getType() const
{
    return this->_type;
}

std::string Toy::getName() const
{
    return this->_name;
}

void Toy::setName(const std::string &name)
{
    this->_name = name;
}

std::string Toy::getAscii() const
{
    return this->_picture.data;
}

bool Toy::setAscii(const std::string &filename)
{
    return this->_picture.getPictureFromFile(filename);
}

Toy& Toy::operator<<(const std::string &ascii)
{
    this->_picture.data = ascii;
    return *this;
}

void Toy::speak(const std::string &statement)
{
    std::cout << this->_name << " \"" << statement << "\"" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    return os << toy.getName() << std::endl << toy.getAscii() << std::endl;
}
