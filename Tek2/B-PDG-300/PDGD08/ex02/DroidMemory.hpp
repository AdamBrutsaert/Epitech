/*
** EPITECH PROJECT, 2024
** DroidMemory.hpp
** File description:
** DroidMemory.hpp
*/

#pragma once

#include <iostream>

class DroidMemory {
public:
    DroidMemory();
    DroidMemory(DroidMemory const &droidMemory) = default;
    DroidMemory &operator=(DroidMemory const &droidMemory) = default;
    ~DroidMemory() = default;

    size_t getFingerprint() const { return this->_fingerprint; }
    void setFingerprint(size_t fingerprint) { this->_fingerprint = fingerprint; }

    size_t getExp() const { return this->_exp; }
    void setExp(size_t exp) { this->_exp = exp; }

    DroidMemory &operator<<(DroidMemory const &rhs);
    DroidMemory &operator>>(DroidMemory &rhs);

    DroidMemory &operator+=(DroidMemory const &rhs);
    DroidMemory &operator+=(size_t const &rhs);

    DroidMemory operator+(DroidMemory const &rhs) const;
    DroidMemory operator+(size_t rhs) const;

    bool operator==(DroidMemory const &rhs) const { return this->_fingerprint == rhs._fingerprint && this->_exp == rhs._exp; }
    bool operator!=(DroidMemory const &rhs) const { return !(*this == rhs); }

    bool operator<(DroidMemory const &rhs) const { return this->_exp < rhs._exp; }
    bool operator<(size_t const &rhs) const { return this->_exp < rhs; }
    bool operator>(DroidMemory const &rhs) const { return this->_exp > rhs._exp; }
    bool operator>(size_t const &rhs) const { return this->_exp > rhs; }
    bool operator<=(DroidMemory const &rhs) const { return this->_exp <= rhs._exp; }
    bool operator<=(size_t const &rhs) const { return this->_exp <= rhs; }
    bool operator>=(DroidMemory const &rhs) const { return this->_exp >= rhs._exp; }
    bool operator>=(size_t const &rhs) const { return this->_exp >= rhs; }

private:
    size_t _fingerprint;
    size_t _exp;
};

std::ostream &operator<<(std::ostream &os, DroidMemory const &droidMemory);
