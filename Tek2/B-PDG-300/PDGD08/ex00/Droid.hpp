/*
** EPITECH PROJECT, 2024
** Droid.hpp
** File description:
** Droid.hpp
*/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>

class Droid {
public:
    Droid(std::string serial = "");
    Droid(const Droid &droid);
    Droid &operator=(const Droid &droid);
    ~Droid();

    bool operator==(const Droid &droid) const;
    bool operator!=(const Droid &droid) const { return !(*this == droid); };

    Droid &operator<<(size_t &energy);

    std::string getId() const { return this->_id; };
    void setId(std::string id) { this->_id = id; };

    size_t getEnergy() const { return this->_energy; };
    void setEnergy(size_t energy) { this->_energy = std::clamp<size_t>(energy, 0, 100); };

    size_t getAttack() const { return this->_attack; };
    size_t getToughness() const { return this->_toughness; };

    std::string *getStatus() const { return this->_status; };
    void setStatus(std::string *status) { delete this->_status; this->_status = status; };

private:
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    std::string *_status;
};

std::ostream& operator<<(std::ostream& os, const Droid& droid);
