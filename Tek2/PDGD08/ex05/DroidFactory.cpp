/*
** EPITECH PROJECT, 2024
** DroidFactory.cpp
** File description:
** DroidFactory.cpp
*/

#include "DroidFactory.hpp"

#include <cstdint>

DroidFactory::DroidFactory(size_t ratio)
    : _ratio(ratio), _iron(0), _silicon(0), _exp(0)
{
}

DroidFactory &DroidFactory::operator<<(Supply &supply)
{
    // Retrieve ressources
    switch (supply.getType()) {
    case Supply::Iron:
        this->_iron += supply.getAmount();
        break;
    case Supply::Silicon:
        this->_silicon += supply.getAmount();
        break;
    case Supply::Wreck:
        if (supply.getWrecks() == nullptr)
            break;

        for (size_t i = 0; i < supply.getAmount(); i++) {
            this->_iron += 80;
            this->_silicon += 30;

            if (supply->getBattleData()->getExp() > this->_exp) {
                intmax_t diff = supply->getBattleData()->getExp() - this->_exp;
                this->_exp += std::abs(diff) / this->_ratio;
            }

            ++supply;
        }
        break;
    }

    // Empty the container
    !supply;

    return *this;
}

DroidFactory &DroidFactory::operator>>(Droid *&droid)
{
    if (this->_iron < 100 || this->_silicon < 50) {
        droid = nullptr;
        return *this;
    }

    this->_iron -= 100;
    this->_silicon -= 50;

    size_t xp = this->_exp - this->_exp / this->_ratio;

    droid = new Droid("");
    droid->getBattleData()->setExp(xp);

    return *this;
}

std::ostream &operator<<(std::ostream &os, DroidFactory const &droidMemory)
{
    return os << "DroidFactory status report :" << std::endl
        << "Iron : " << droidMemory.getIron() << std::endl
        << "Silicon : " << droidMemory.getSilicon() << std::endl
        << "Exp : " << droidMemory.getExp() << std::endl
        << "End of status report.";
}

DroidFactory &operator>>(Supply &supply, DroidFactory &factory)
{
    return factory << supply;
}

DroidFactory &operator>>(Droid *&droid, DroidFactory &factory)
{
    return factory >> droid;
}
