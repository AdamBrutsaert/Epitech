/*
** EPITECH PROJECT, 2024
** Parts.hpp
** File description:
** Parts.hpp
*/

#pragma once

#include <string>

class Part {
public:
    Part(const std::string &serial, bool functional) noexcept;
    ~Part() = default;

    bool isFunctional() const noexcept { return this->_functionnal; }
    std::string serial() const noexcept { return this->_serial; }
    virtual void informations() const noexcept = 0;
protected:
    std::string _serial;
    bool _functionnal;
};

class Arms : public Part {
public:
    Arms(const std::string &serial = "A-01", bool functionnal = true) noexcept;

    void informations() const noexcept final;
};

class Legs : public Part {
public:
    Legs(const std::string &serial = "L-01", bool functionnal = true) noexcept;

    void informations() const noexcept final;
};

class Head : public Part {
public:
    Head(const std::string &serial = "H-01", bool functionnal = true) noexcept;

    void informations() const noexcept final;
};
