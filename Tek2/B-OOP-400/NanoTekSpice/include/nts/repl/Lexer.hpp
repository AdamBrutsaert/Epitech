/*
** EPITECH PROJECT, 2024
** Lexer.hpp
** File description:
** Lexer.hpp
*/

#pragma once

#include "Reader.hpp"
#include "Token.hpp"

#include <memory>
#include <optional>
#include <vector>

namespace nts::repl {
    class Lexer {
    public:
        Lexer(std::unique_ptr<Reader>&& reader);
        Lexer(const Lexer&) = delete;
        Lexer(Lexer&&) = delete;
        Lexer& operator=(const Lexer&) = delete;
        Lexer& operator=(Lexer&&) = delete;
        ~Lexer() = default;

        bool read();

        Token next();
        Token peek() const;

        std::vector<Token> all();

    private:
        std::unique_ptr<Reader> _reader;
        mutable std::optional<Token> _peeked;
    };
}
