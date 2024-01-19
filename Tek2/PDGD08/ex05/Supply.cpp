/*
** EPITECH PROJECT, 2024
** Supply.cpp
** File description:
** Supply.cpp
*/

#include "Supply.hpp"

Supply::Supply(Types type, size_t amount)
    : _type(type), _amount(amount), _index(0), _wrecks(nullptr)
{
}

Supply::Supply(Types type, size_t amount, Droid **wrecks)
    : _type(type), _amount(amount), _index(0), _wrecks(wrecks)
{
}

Supply::~Supply()
{
    if (_wrecks == nullptr)
        return;
    for (size_t i = 0; i < _amount; i++)
        delete _wrecks[i];
}

Supply &Supply::operator++()
{
    if (_wrecks == nullptr)
        return *this;
    _index++;
    if (_index >= _amount)
        _index = 0;
    return *this;
}

Supply &Supply::operator--()
{
    if (_wrecks == nullptr)
        return *this;
    if (_index == 0) {
        _index = _amount - (_amount != 0);
    } else {
        _index--;
    }
    return *this;
}

Supply &Supply::operator!()
{
    if (_wrecks == nullptr) {
        _amount = 0;
        return *this;
    }
    for (size_t i = 0; i < _amount; i++)
        delete _wrecks[i];
    this->_amount = 0;
    return *this;
}

std::ostream &operator<<(std::ostream &os, Supply const &supply)
{
    os << "Supply : " << supply.getAmount() << ", ";

    switch(supply.getType()) {
    case Supply::Iron:
        os << "Iron";
        break;
    case Supply::Silicon:
        os << "Silicon";
        break;
    case Supply::Wreck:
        os << "Wreck";

        if (supply.getWrecks() == nullptr)
            break;

        for (size_t i = 0; i < supply.getAmount(); i++)
            os << std::endl << *supply.getWrecks()[i];

        break;
    }

    return os;
}
