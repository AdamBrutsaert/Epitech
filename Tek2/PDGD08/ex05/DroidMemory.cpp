/*
** EPITECH PROJECT, 2024
** DroidMemory.cpp
** File description:
** DroidMemory.cpp
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
    : _fingerprint(random()), _exp(0)
{
}

DroidMemory &DroidMemory::operator<<(DroidMemory const &rhs)
{
    this->_exp += rhs._exp;
    this->_fingerprint ^= rhs._fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &rhs)
{
    rhs._exp += this->_exp;
    rhs._fingerprint ^= this->_fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(DroidMemory const &rhs)
{
    return *this << rhs;
}

DroidMemory &DroidMemory::operator+=(size_t const &rhs)
{
    this->_exp += rhs;
    this->_fingerprint ^= rhs;
    return *this;
}

DroidMemory DroidMemory::operator+(DroidMemory const &rhs) const
{
    return DroidMemory(*this) += rhs;
}

DroidMemory DroidMemory::operator+(size_t rhs) const
{
    return DroidMemory(*this) += rhs;
}

std::ostream &operator<<(std::ostream &os, DroidMemory const &droidMemory)
{
    return os << "DroidMemory '" << droidMemory.getFingerprint() << "', " << droidMemory.getExp();
}
