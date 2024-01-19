/*
** EPITECH PROJECT, 2024
** KreogCom.hpp
** File description:
** KreogCom.hpp
*/

#pragma once

class KreogCom {
public:
    KreogCom(int x, int y, int serial);
    ~KreogCom();

    void addCom(int x, int y, int serial);
    void removeCom();
    KreogCom *getCom() const { return this->m_next; };

    void ping() const;
    void locateSquad() const;
private:
    const int m_serial;
    int m_x;
    int m_y;
    KreogCom *m_next;
    KreogCom *m_prev;
};
