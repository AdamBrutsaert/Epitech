/*
** EPITECH PROJECT, 2024
** Toy.hpp
** File description:
** Toy.hpp
*/

#pragma once

#include "Picture.hpp"

#include <iostream>

class Toy {
public:
    class Error {
    public:
        enum ErrorType {
            UNKNOWN = 0,
            PICTURE,
            SPEAK
        };

    public:
        ErrorType type;

    public:
        Error(ErrorType type, const std::string &function, const std::string &message);

        const std::string &what() const;
        const std::string &where() const;

    private:
        std::string _function;
        std::string _message;
    };

    enum ToyType {
        BASIC_TOY = 0,
        ALIEN,
        BUZZ,
        WOODY
    };

public:
    Toy();
    Toy(ToyType type, const std::string &name, const std::string &filename);
    Toy(const Toy &toy) = default;
    Toy(Toy &&toy) = default;
    Toy& operator=(const Toy &toy) = default;
    Toy& operator=(Toy &&toy) = default;
    virtual ~Toy() = default;

    ToyType getType() const;

    std::string getName() const;
    void setName(const std::string &name);

    std::string getAscii() const;
    bool setAscii(const std::string &filename);
    Toy& operator<<(const std::string &ascii);

    virtual bool speak(const std::string &statement);
    virtual bool speak_es(const std::string &statement);

    Error getLastError() const;

protected:
    Error _error;

private:
    ToyType _type;
    std::string _name;
    Picture _picture;
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);
