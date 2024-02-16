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

    virtual bool speak(const std::string &statement) override;
    virtual bool speak_es(const std::string &statement) override;
};
