/*
** EPITECH PROJECT, 2024
** Parsing.hpp
** File description:
** Parsing.hpp
*/

#pragma once

#include "nts/Circuit.hpp"
#include "Token.hpp"

namespace nts::conf {
    /// Thrown when a file could not be loaded
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

    /// Thrown when an unexpected token is found
    class UnexpectedToken : public std::exception {
    public:
        UnexpectedToken(Token&& token, Token::Type expected);
        UnexpectedToken(const UnexpectedToken&) = default;
        UnexpectedToken(UnexpectedToken&&) = default;
        UnexpectedToken& operator=(const UnexpectedToken&) = default;
        UnexpectedToken& operator=(UnexpectedToken&&) = default;
        virtual ~UnexpectedToken() noexcept override = default;

        inline virtual const char* what() const noexcept override { return this->_what.c_str(); }

    private:
        std::string _what;
    };

    /// Thrown when a component type is invalid
    class InvalidComponentType : public std::exception {
    public:
        InvalidComponentType(std::size_t line, std::size_t column, const std::string& type);
        InvalidComponentType(const InvalidComponentType&) = default;
        InvalidComponentType(InvalidComponentType&&) = default;
        InvalidComponentType& operator=(const InvalidComponentType&) = default;
        InvalidComponentType& operator=(InvalidComponentType&&) = default;
        virtual ~InvalidComponentType() noexcept override = default;

        inline virtual const char* what() const noexcept override { return this->_what.c_str(); }

    private:
        std::string _what;
    };

    /// Thrown when a component already exists
    class ComponentAlreadyExists : public std::exception {
    public:
        ComponentAlreadyExists(std::size_t line, std::size_t column, const std::string& name);
        ComponentAlreadyExists(const ComponentAlreadyExists&) = default;
        ComponentAlreadyExists(ComponentAlreadyExists&&) = default;
        ComponentAlreadyExists& operator=(const ComponentAlreadyExists&) = default;
        ComponentAlreadyExists& operator=(ComponentAlreadyExists&&) = default;
        virtual ~ComponentAlreadyExists() noexcept override = default;

        inline virtual const char* what() const noexcept override { return this->_what.c_str(); }

    private:
        std::string _what;
    };

    /// Thrown when a component is not found
    class ComponentNotFound : public std::exception {
    public:
        ComponentNotFound(std::size_t line, std::size_t column, const std::string& name);
        ComponentNotFound(const ComponentNotFound&) = default;
        ComponentNotFound(ComponentNotFound&&) = default;
        ComponentNotFound& operator=(const ComponentNotFound&) = default;
        ComponentNotFound& operator=(ComponentNotFound&&) = default;
        virtual ~ComponentNotFound() noexcept override = default;

        inline virtual const char* what() const noexcept override { return this->_what.c_str(); }

    private:
        std::string _what;
    };

    /// Thrown when a pin is out-of-range
    class PinOutOfRange : public std::exception {
    public:
        PinOutOfRange(std::size_t line, std::size_t column, const std::string& name, std::size_t pin);
        PinOutOfRange(const PinOutOfRange&) = default;
        PinOutOfRange(PinOutOfRange&&) = default;
        PinOutOfRange& operator=(const PinOutOfRange&) = default;
        PinOutOfRange& operator=(PinOutOfRange&&) = default;
        virtual ~PinOutOfRange() noexcept override = default;

        inline virtual const char* what() const noexcept override { return this->_what.c_str(); }

    private:
        std::string _what;
    };

    /// Thrown when none of the pin of a link is of type Input
    class InvalidInputPin : public std::exception {
    public:
        InvalidInputPin(std::size_t line, std::size_t column, const std::string& name, std::size_t pin);
        InvalidInputPin(const InvalidInputPin&) = default;
        InvalidInputPin(InvalidInputPin&&) = default;
        InvalidInputPin& operator=(const InvalidInputPin&) = default;
        InvalidInputPin& operator=(InvalidInputPin&&) = default;
        virtual ~InvalidInputPin() noexcept override = default;

        inline virtual const char* what() const noexcept override { return this->_what.c_str(); }

    private:
        std::string _what;
    };

    /// Thrown when none of the pin of a link is of type Output
    class InvalidOutputPin : public std::exception {
    public:
        InvalidOutputPin(std::size_t line, std::size_t column, const std::string& name, std::size_t pin);
        InvalidOutputPin(const InvalidOutputPin&) = default;
        InvalidOutputPin(InvalidOutputPin&&) = default;
        InvalidOutputPin& operator=(const InvalidOutputPin&) = default;
        InvalidOutputPin& operator=(InvalidOutputPin&&) = default;
        virtual ~InvalidOutputPin() noexcept override = default;

        inline virtual const char* what() const noexcept override { return this->_what.c_str(); }

    private:
        std::string _what;
    };

    /// Thrown when the circuit is not well-formed
    class InvalidCircuit : public std::exception {
    public:
        InvalidCircuit();
        InvalidCircuit(const InvalidCircuit&) = default;
        InvalidCircuit(InvalidCircuit&&) = default;
        InvalidCircuit& operator=(const InvalidCircuit&) = default;
        InvalidCircuit& operator=(InvalidCircuit&&) = default;
        virtual ~InvalidCircuit() noexcept override = default;

        inline virtual const char* what() const noexcept override { return this->_what.c_str(); }

    private:
        std::string _what;
    };

    std::unique_ptr<Circuit> parse(const std::string& filename);
}
