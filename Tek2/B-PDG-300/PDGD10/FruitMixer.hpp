/*
** EPITECH PROJECT, 2024
** FruitMixer.hpp
** File description:
** FruitMixer.hpp
*/

#pragma once

#include "IFruitMixer.hpp"

class FruitMixer : public IFruitMixer {
public:
    FruitMixer();

    virtual unsigned int mixFruits(FruitBox& box) const override;
    virtual void setBlade(IBlade* blade) override;

private:
    IBlade *_blade;
};
