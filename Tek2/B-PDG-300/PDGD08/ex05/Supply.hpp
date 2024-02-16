/*
** EPITECH PROJECT, 2024
** Supply.hpp
** File description:
** Supply.hpp
*/

#pragma once

#include "Droid.hpp"

class Supply {
public:
    enum Types {
        Iron = 1,
        Silicon = 2,
        Wreck = 3,
    };

    Supply(Types type, size_t amount);
    Supply(Types type, size_t amount, Droid **wrecks);
    Supply(Supply const &supply) = delete;
    Supply &operator=(Supply const &supply) = delete;
    ~Supply();

    Droid *&operator*() { return _wrecks[_index]; }
    Droid *&operator->() { return _wrecks[_index]; }
    const Droid *operator*() const { return _wrecks[_index]; }
    const Droid *operator->() const { return _wrecks[_index]; }
    Supply &operator++();
    Supply &operator--();
    Supply &operator!();
    bool operator==(Supply const &supply) const { return _type == supply._type; }
    bool operator!=(Supply const &supply) const { return _type != supply._type; }

    operator size_t() { return _amount; }
    operator size_t() const { return _amount; }

    Types getType() const { return _type; }
    void setType(Types type) { _type = type; }

    size_t getAmount() const { return _amount; }
    void setAmount(size_t amount) { _amount = amount; }

    size_t getIndex() const { return _index; }
    void setIndex(size_t index) { _index = index; }

    Droid **getWrecks() const { return _wrecks; }
    void setWrecks(Droid **wrecks) { _wrecks = wrecks; }

private:
    Types _type;
    size_t _amount;
    size_t _index;
    Droid **_wrecks;
};

std::ostream &operator<<(std::ostream &os, Supply const &supply);
