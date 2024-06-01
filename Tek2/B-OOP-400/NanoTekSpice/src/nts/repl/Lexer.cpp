/*
** EPITECH PROJECT, 2024
** Lexer.cpp
** File description:
** Lexer.cpp
*/

#include "nts/repl/Lexer.hpp"

namespace nts::repl {
    Lexer::Lexer(std::unique_ptr<Reader>&& reader)
        : _reader(std::move(reader)), _peeked()
    {
    }

    bool Lexer::read()
    {
        return this->_reader->read();
    }


    static Token next(Reader *reader)
    {
        reader->skipWhitespace();

        switch (reader->peek()) {
        case '=':
            reader->next();
            return Token{Token::Type::EQUAL, "="};
        case '\0':
            return Token{Token::Type::END, ""};
        }

        std::string word = reader->nextWord();

        if (word == "")
            return Token{Token::Type::UNKNOWN, reader->nextUnexpectedWord()};

        return Token{Token::Type::STRING, std::move(word)};
    }

    Token Lexer::next()
    {
        if (this->_peeked.has_value()) {
            Token token = std::move(this->_peeked.value());
            this->_peeked.reset();
            return token;
        }

        return nts::repl::next(this->_reader.get());
    }

    Token Lexer::peek() const
    {
        if (!this->_peeked.has_value())
            this->_peeked = nts::repl::next(this->_reader.get());

        return this->_peeked.value();
    }

    std::vector<Token> Lexer::all()
    {
        std::vector<Token> tokens;
        Token::Type type = Token::Type::UNKNOWN;

        while (type != Token::Type::END) {
            Token token = this->next();
            type = token.type();
            tokens.push_back(std::move(token));
        }

        return tokens;
    }
}
