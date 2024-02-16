/*
** EPITECH PROJECT, 2024
** Carrier.hpp
** File description:
** Carrier.hpp
*/

#pragma once

#include "Droid.hpp"

#include <algorithm>

class Carrier {
public:
    Carrier(std::string id);
    Carrier(const Carrier &carrier) = delete;
    Carrier &operator=(const Carrier &carrier) = delete;
    ~Carrier();

    Carrier &operator<<(Droid *&droid);
    Carrier &operator<<(size_t &energy);
    Carrier &operator>>(Droid *&droid);

    Droid *&operator[](size_t index) { return this->_droids[index]; }
    Droid *operator[](size_t index) const { return this->_droids[index]; }

    Carrier &operator~();
    bool operator()(int x, int y);

    std::string getId() const { return this->_id; }
    void setId(std::string id) { this->_id = id; }

    size_t getEnergy() const { return this->_energy; }
    void setEnergy(size_t energy) { this->_energy = std::clamp<size_t>(energy, 0, 600); };

    size_t getAttack() const { return this->attack; }
    size_t getToughness() const { return this->toughness; }

    size_t getSpeed() const { return this->_speed; }
    void setSpeed(size_t speed) { this->_speed = speed; }

    int getX() const { return this->_x; }
    void setX(int x) { this->_x = x; }

    int getY() const { return this->_y; }
    void setY(int y) { this->_y = y; }

private:
    size_t getDroidsCount() const;

    std::string _id;
    size_t _energy;
    const size_t attack;
    const size_t toughness;
    size_t _speed;
    Droid *_droids[5];
    int _x;
    int _y;
};

std::ostream& operator<<(std::ostream& os, const Carrier& carrier);
