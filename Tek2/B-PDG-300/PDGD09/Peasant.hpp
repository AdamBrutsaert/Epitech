/*
** EPITECH PROJECT, 2024
** Peasant.hpp
** File description:
** Peasant.hpp
*/

#pragma once

#include "ICharacter.hpp"

class Peasant : public ICharacter {
public:
    Peasant(const std::string &name, int power);
    virtual ~Peasant();

    virtual const std::string &getName() const override { return this->_name; }
    virtual int getPower() const override { return this->_power; }
    virtual int getHp() const override { return this->_health; }

    virtual int attack() override;
    virtual int special() override;
    virtual void rest() override;
    virtual void damage(int damage) override;

    virtual void drink(const IPotion &potion) override;
    virtual void drink(const HealthPotion &potion) override;
    virtual void drink(const PowerPotion &potion) override;
    virtual void drink(const PoisonPotion &potion) override;

protected:

    void _tell(const std::string &message);
    bool _checkHealth();
    bool _checkPower(int minPower);

    std::string _name;
    int _power;
    int _health;
};
