/*
** EPITECH PROJECT, 2024
** Toy.hpp
** File description:
** Toy.hpp
*/

#pragma once

#include "Picture.hpp"

class Toy {
public:
    enum ToyType {
        BASIC_TOY = 0,
        ALIEN
    };

public:
    Toy();
    Toy(ToyType type, const std::string &name, const std::string &filename);
    virtual ~Toy() = default;

    ToyType getType() const;

    std::string getName() const;
    void setName(const std::string &name);

    std::string getAscii() const;
    bool setAscii(const std::string &filename);

private:
    ToyType _type;
    std::string _name;
    Picture _picture;
};
