/*
** EPITECH PROJECT, 2024
** KoalaBot.hpp
** File description:
** KoalaBot.hpp
*/

#pragma once

#include <string>

#include "Parts.hpp"

class KoalaBot {
public:
    KoalaBot(const std::string &serial = "Bob-01") noexcept;
    ~KoalaBot() = default;

    void setParts(const Arms &arms) noexcept { this->_arms = arms; }
    void setParts(const Legs &legs) noexcept { this->_legs = legs; }
    void setParts(const Head &head) noexcept { this->_head = head; };

    void swapParts(Arms &arms) noexcept { std::swap(arms, this->_arms); }
    void swapParts(Legs &legs) noexcept { std::swap(legs, this->_legs); }
    void swapParts(Head &head) noexcept { std::swap(head, this->_head); }

    void informations() const noexcept;
    bool status() const noexcept { return this->_arms.isFunctional() && this->_legs.isFunctional() && this->_head.isFunctional(); }

private:
    std::string _serial;
    Arms _arms;
    Legs _legs;
    Head _head;
};
