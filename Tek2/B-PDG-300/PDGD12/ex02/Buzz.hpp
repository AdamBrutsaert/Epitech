/*
** EPITECH PROJECT, 2024
** Buzz.hpp
** File description:
** Buzz.hpp
*/

#pragma once

#include "Toy.hpp"

class Buzz : public Toy {
public:
    Buzz(const std::string &name);
    Buzz(const std::string &name, const std::string &file);
};
