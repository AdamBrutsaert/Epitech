/*
** EPITECH PROJECT, 2024
** Priest.hpp
** File description:
** Priest.hpp
*/

#pragma once

#include "Enchanter.hpp"

class Priest : public Enchanter {
public:
    Priest(const std::string &name, int power);
    virtual ~Priest();

    void rest() override;
};
