/*
** EPITECH PROJECT, 2024
** Toy.cpp
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Error::Error(ErrorType type, const std::string &function, const std::string &message)
    : type(type), _function(function), _message(message)
{
}

const std::string &Toy::Error::what() const
{
    return this->_message;
}

const std::string &Toy::Error::where() const
{
    return this->_function;
}

Toy::Toy()
    : _error(Error::ErrorType::UNKNOWN, "", ""), _type(BASIC_TOY), _name("toy"), _picture()
{
}

Toy::Toy(ToyType type, const std::string &name, const std::string &filename)
    : _error(Error::ErrorType::UNKNOWN, "", ""), _type(type), _name(name), _picture(filename)
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
    if (!this->_picture.getPictureFromFile(filename)) {
        this->_error = Error(Error::ErrorType::PICTURE, "setAscii", "bad new illustration");
        return false;
    }

    return true;
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

bool Toy::speak_es([[maybe_unused]] const std::string &statement)
{
    this->_error = Error(Error::ErrorType::SPEAK, "speak_es", "wrong mode");
    return false;
}

Toy::Error Toy::getLastError() const
{
    return this->_error;
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    return os << toy.getName() << std::endl << toy.getAscii() << std::endl;
}
