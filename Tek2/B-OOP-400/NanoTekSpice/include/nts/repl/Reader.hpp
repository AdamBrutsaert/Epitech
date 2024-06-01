/*
** EPITECH PROJECT, 2024
** Reader.hpp
** File description:
** Reader.hpp
*/

#pragma once

#include <string>

namespace nts::repl {
    class Reader {
    public:
        Reader();
        Reader(const Reader &) = delete;
        Reader(Reader &&) = delete;
        Reader &operator=(const Reader &) = delete;
        Reader &operator=(Reader &&) = delete;
        ~Reader() = default;

        bool read();

        char next();
        char peek() const;

        std::string nextWord();
        std::string nextUnexpectedWord();

        void skipWhitespace();

    private:
        std::string _buffer;
        std::size_t _cursor;
    };
};
