/*
** EPITECH PROJECT, 2024
** Lexer.cpp
** File description:
** Lexer.cpp
*/

#include "nts/configuration/Lexer.hpp"

namespace nts::conf {
    Lexer::Lexer(std::unique_ptr<Reader>&& reader)
        : _reader(std::move(reader)), _peeked(std::nullopt)
    {
    }

    static bool isStringDigits(const std::string& string)
    {
        for (char c : string) {
            if (c < '0' || c > '9')
                return false;
        }
        return true;
    }

    static Token next(Reader *reader)
    {
        // Skip whitespace
        reader->skipWhitespaceUntilNewline();

        // Skip comment
        if (reader->peek() == '#')
            reader->skipUntilNewline();

        std::size_t line = reader->line();
        std::size_t column = reader->column();

        // Single char tokens
        switch (reader->peek()) {
            case ':':
                reader->next();
                return Token{Token::Type::COLON, ":", line, column};
            case '\n':
                reader->next();
                return Token{Token::Type::NEWLINE, "\n", line, column};
            case '\0':
                return Token{Token::Type::END, "", line, column};
        }

        // Keyword tokens
        std::string word = reader->nextWord();

        if (word == "")
            return Token{Token::Type::UNKNOWN, reader->nextUnexpectedWord(), line, column};
        if (word == ".chipsets")
            return Token{Token::Type::DOT_CHIPSETS, std::move(word), line, column};
        if (word == ".links")
            return Token{Token::Type::DOT_LINKS, std::move(word), line, column};

        // String or number tokens
        if (isStringDigits(word))
            return Token{Token::Type::NUMBER, std::move(word), line, column};

        return Token{Token::Type::STRING, std::move(word), line, column};
    }

    Token Lexer::next()
    {
        if (this->_peeked.has_value()) {
            Token token = std::move(this->_peeked.value());
            this->_peeked.reset();
            return token;
        }

        return nts::conf::next(this->_reader.get());
    }

    Token Lexer::peek() const
    {
        if (!this->_peeked.has_value())
            this->_peeked = nts::conf::next(this->_reader.get());

        return this->_peeked.value();
    }

    void Lexer::skipNewlines()
    {
        while (this->peek().type() == Token::Type::NEWLINE)
            this->next();
    }
}
