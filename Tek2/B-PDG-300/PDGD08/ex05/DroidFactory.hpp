/*
** EPITECH PROJECT, 2024
** DroidFactory.hpp
** File description:
** DroidFactory.hpp
*/

#pragma once

#include "Supply.hpp"

class DroidFactory {
public:
    explicit DroidFactory(size_t ratio = 2);
    DroidFactory(DroidFactory const &other) = default;
    DroidFactory &operator=(DroidFactory const &other) = default;
    ~DroidFactory() = default;

    DroidFactory &operator++() { this->_ratio++; return *this; }
    DroidFactory operator++(int) { DroidFactory tmp(*this); operator++(); return tmp; }
    DroidFactory &operator--() { this->_ratio = std::max<size_t>(this->_ratio - 1, 1); return *this; }
    DroidFactory operator--(int) { DroidFactory tmp(*this); operator--(); return tmp; }

    DroidFactory &operator<<(Supply &supply);
    DroidFactory &operator>>(Droid *&droid);

    size_t getRatio() const { return this->_ratio; }
    void setRatio(size_t ratio) { this->_ratio = ratio; }

    size_t getIron() const { return this->_iron; }
    void setIron(size_t iron) { this->_iron = iron; }

    size_t getSilicon() const { return this->_silicon; }
    void setSilicon(size_t silicon) { this->_silicon = silicon; }

    size_t getExp() const { return this->_exp; }
    void setExp(size_t exp) { this->_exp = exp; }

private:
    size_t _ratio;

    size_t _iron;
    size_t _silicon;
    size_t _exp;
};

std::ostream &operator<<(std::ostream &os, DroidFactory const &droidMemory);
DroidFactory &operator>>(Supply &supply, DroidFactory &factory);
DroidFactory &operator>>(Droid *&droid, DroidFactory &factory);
