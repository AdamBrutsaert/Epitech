/*
** EPITECH PROJECT, 2024
** AFruit.hpp
** File description:
** AFruit.hpp
*/

#pragma once

#include "IFruit.hpp"

class AFruit : public IFruit {
public:
    AFruit();

    virtual unsigned int getVitamins() const override;
    virtual bool isPeeled() const override;
    virtual void peel() override;
protected:
    AFruit(bool peeled, unsigned int vitamins);

    bool _peeled;
    unsigned int _vitamins;
};
