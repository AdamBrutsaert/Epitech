/*
** EPITECH PROJECT, 2024
** Woody.hpp
** File description:
** Woody.hpp
*/

#pragma once

#include "Toy.hpp"

class Woody : public Toy {
public:
    Woody(const std::string &name);
    Woody(const std::string &name, const std::string &file);
};
