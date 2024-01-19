/*
** EPITECH PROJECT, 2024
** Phaser.hpp
** File description:
** Phaser.hpp
*/

#pragma once

#include <deque>

class Phaser {
public:
    enum AmmoType {
        REGULAR,
        PLASMA,
        ROCKET,
    };

    Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
    ~Phaser() = default;

    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);

    int getCurrentAmmos() const;

private:
    static const int Empty;

    int _maxAmmo;
    AmmoType _defaultType;
    std::deque<AmmoType> _magazine;
};
