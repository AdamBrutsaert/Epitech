/*
** EPITECH PROJECT, 2024
** Picture.cpp
** File description:
** Picture.cpp
*/

#include "Picture.hpp"

#include <fstream>
#include <sstream>

Picture::Picture(const std::string &file)
{
    this->getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream handle(file);

    if (!handle) {
        this->data = "ERROR";
        return false;
    }

    std::stringstream buffer;
    buffer << handle.rdbuf();
    this->data = buffer.str();
    return true;
}
