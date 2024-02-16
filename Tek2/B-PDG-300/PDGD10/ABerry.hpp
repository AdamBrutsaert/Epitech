/*
** EPITECH PROJECT, 2024
** ABerry.hpp
** File description:
** ABerry.hpp
*/

#pragma once

#include "AFruit.hpp"

class ABerry : public AFruit {
public:
    virtual bool isPeeled() const override;
protected:
    ABerry(bool peeled, unsigned int vitamins);
};
