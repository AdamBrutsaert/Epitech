/*
** EPITECH PROJECT, 2024
** Reader.hpp
** File description:
** Reader.hpp
*/

#pragma once

#include <string>

namespace nts::conf {
    class Reader {
    public:
        class LoadFailure : public std::exception {
        public:
            LoadFailure(const std::string& filename);
            LoadFailure(const LoadFailure&) = default;
            LoadFailure(LoadFailure&&) = default;
            LoadFailure& operator=(const LoadFailure&) = default;
            LoadFailure& operator=(LoadFailure&&) = default;
            virtual ~LoadFailure() noexcept override = default;

            inline virtual const char* what() const noexcept override { return this->_what.c_str(); }

        private:
            std::string _what;
        };

    public:
        Reader(const std::string& filename);
        Reader(const Reader&) = delete;
        Reader(Reader&&) = default;
        Reader& operator=(const Reader&) = delete;
        Reader& operator=(Reader&&) = default;
        ~Reader() noexcept = default;

        inline std::size_t line() const { return this->_line; }
        inline std::size_t column() const { return this->_column; }

        char next();
        char peek() const;

        std::string nextWord();
        std::string nextUnexpectedWord();

        void skipWhitespaceUntilNewline();
        void skipUntilNewline();

    private:
        std::string _buffer;
        std::size_t _cursor;
        std::size_t _line;
        std::size_t _column;
    };
}
