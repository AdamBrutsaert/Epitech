/*
** EPITECH PROJECT, 2024
** KreogCom.cpp
** File description:
** KreogCom.cpp
*/

#include "KreogCom.hpp"

#include <iostream>

KreogCom::KreogCom(int x, int y, int serial)
    : m_serial(serial), m_x(x), m_y(y), m_next(nullptr), m_prev(nullptr)
{
    std::cout << "KreogCom " << this->m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;

    if (this->m_prev != nullptr)
        this->m_prev->m_next = this->m_next;
    if (this->m_next != nullptr)
        this->m_next->m_prev = this->m_prev;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newCom = new KreogCom(x, y, serial);

    newCom->m_next = this->m_next;
    newCom->m_prev = this;
    this->m_next = newCom;
    if (newCom->m_next != nullptr)
        newCom->m_next->m_prev = newCom;
}

void KreogCom::removeCom()
{
    if (this->m_next != nullptr) {
        KreogCom *tmp = this->m_next;
        this->m_next = this->m_next->m_next;
        if (this->m_next != nullptr)
            this->m_next->m_prev = this;
        delete tmp;
    }
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->m_serial << " currently at "
              << this->m_x << " " << this->m_y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = this->m_next;

    while (tmp != nullptr) {
        tmp->ping();
        tmp = tmp->m_next;
    }

    this->ping();
}
