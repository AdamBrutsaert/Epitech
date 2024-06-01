/*
** EPITECH PROJECT, 2024
** Lexer.hpp
** File description:
** Lexer.hpp
*/

#pragma once

#include "Reader.hpp"
#include "Token.hpp"

#include <optional>
#include <memory>

namespace nts::conf {
    class Lexer {
    public:
        Lexer(std::unique_ptr<Reader>&& reader);
        Lexer(const Lexer&) = delete;
        Lexer(Lexer&&) = default;
        Lexer& operator=(const Lexer&) = delete;
        Lexer& operator=(Lexer&&) = default;
        ~Lexer() = default;

        Token next();
        Token peek() const;

        void skipNewlines();

    private:
        std::unique_ptr<Reader> _reader;
        mutable std::optional<Token> _peeked;
    };
}
