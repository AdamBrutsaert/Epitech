/*
** EPITECH PROJECT, 2024
** Parsing.cpp
** File description:
** Parsing.cpp
*/

#include "nts/configuration/Parsing.hpp"
#include "nts/configuration/Lexer.hpp"
#include "nts/components/ComponentFactory.hpp"

namespace nts::conf {
    LoadFailure::LoadFailure(const std::string& filename)
        : _what("Failed to load file \"" + filename + "\"")
    {
    }

    UnexpectedToken::UnexpectedToken(Token&& token, Token::Type expected)
    {
        std::string value = token.value();

        if (token.type() == Token::Type::NEWLINE)
            value = "\\n";

        this->_what = std::string("[") + std::to_string(token.line()) + ":" + std::to_string(token.column())
            + "] Unexpected token " + Token::TypeToString(token.type()) + " \"" + value + "\""
            + " (expected type " + Token::TypeToString(expected) + ")";
    }

    InvalidComponentType::InvalidComponentType(std::size_t line, std::size_t column, const std::string& type)
    {
        this->_what = std::string("[") + std::to_string(line) + ":" + std::to_string(column)
            + "] Invalid component type \"" + type + "\"";
    }

    ComponentAlreadyExists::ComponentAlreadyExists(std::size_t line, std::size_t column, const std::string& name)
    {
        this->_what = std::string("[") + std::to_string(line) + ":" + std::to_string(column)
            + "] Component \"" + name + "\" already exists";
    }

    ComponentNotFound::ComponentNotFound(std::size_t line, std::size_t column, const std::string& name)
    {
        this->_what = std::string("[") + std::to_string(line) + ":" + std::to_string(column)
            + "] Component \"" + name + "\" not found";
    }

    PinOutOfRange::PinOutOfRange(std::size_t line, std::size_t column, const std::string& name, std::size_t pin)
    {
        this->_what = std::string("[") + std::to_string(line) + ":" + std::to_string(column)
            + "] Pin " + std::to_string(pin) + " of component \"" + name + "\" is out of range";
    }

    InvalidInputPin::InvalidInputPin(std::size_t line, std::size_t column, const std::string& name, std::size_t pin)
    {
        this->_what = std::string("[") + std::to_string(line) + ":" + std::to_string(column)
            + "] Cannot link pin " + std::to_string(pin) + " of component \"" + name + "\" to an output pin";
    }

    InvalidOutputPin::InvalidOutputPin(std::size_t line, std::size_t column, const std::string& name, std::size_t pin)
    {
        this->_what = std::string("[") + std::to_string(line) + ":" + std::to_string(column)
            + "] Cannot link pin " + std::to_string(pin) + " of component \"" + name + "\" to an input pin";
    }

    InvalidCircuit::InvalidCircuit()
        : _what("Invalid circuit")
    {
    }
}

namespace nts::conf {
    static void parseChipset(Lexer& lexer, Circuit& circuit)
    {
        Token token1 = lexer.next();
        Token token2 = lexer.next();
        Token token3 = lexer.next();

        if (token1.type() != Token::Type::STRING && token1.type() != Token::Type::NUMBER)
            throw nts::conf::UnexpectedToken(std::move(token1), Token::Type::STRING);
        if (token2.type() != Token::Type::STRING)
            throw nts::conf::UnexpectedToken(std::move(token2), Token::Type::STRING);
        if (token3.type() != Token::Type::NEWLINE)
            throw nts::conf::UnexpectedToken(std::move(token3), Token::Type::NEWLINE);

        std::shared_ptr<nts::IComponent> component;

        try {
            component = ComponentFactory::createComponent(token1.value());
        } catch (const ComponentFactory::InvalidComponentType&) {
            throw nts::conf::InvalidComponentType(token1.line(), token1.column(), token1.value());
        }

        try {
            circuit.add(token2.value(), component);
        } catch (const Circuit::ComponentAlreadyExists&) {
            throw nts::conf::ComponentAlreadyExists(token2.line(), token2.column(), token2.value());
        }
    }

    static void parseChipsets(Lexer& lexer, Circuit& circuit)
    {
        Token token1 = lexer.next();
        Token token2 = lexer.next();
        Token token3 = lexer.next();
        lexer.skipNewlines();

        if (token1.type() != Token::Type::DOT_CHIPSETS)
            throw nts::conf::UnexpectedToken(std::move(token1), Token::Type::DOT_CHIPSETS);
        if (token2.type() != Token::Type::COLON)
            throw nts::conf::UnexpectedToken(std::move(token2), Token::Type::COLON);
        if (token3.type() != Token::Type::NEWLINE)
            throw nts::conf::UnexpectedToken(std::move(token3), Token::Type::NEWLINE);

        for (Token token = lexer.peek();
            token.type() != Token::Type::END && token.type() != Token::Type::DOT_LINKS;
            token = lexer.peek()
        ) {
            parseChipset(lexer, circuit);
            lexer.skipNewlines();
        }
    }

    static void parseLink(Lexer& lexer, Circuit& circuit)
    {
        Token token1 = lexer.next();
        Token token2 = lexer.next();
        Token token3 = lexer.next();
        Token token4 = lexer.next();
        Token token5 = lexer.next();
        Token token6 = lexer.next();
        Token token7 = lexer.next();

        if (token1.type() != Token::Type::STRING)
            throw nts::conf::UnexpectedToken(std::move(token1), Token::Type::STRING);
        if (token2.type() != Token::Type::COLON)
            throw nts::conf::UnexpectedToken(std::move(token2), Token::Type::COLON);
        if (token3.type() != Token::Type::NUMBER)
            throw nts::conf::UnexpectedToken(std::move(token3), Token::Type::NUMBER);
        if (token4.type() != Token::Type::STRING)
            throw nts::conf::UnexpectedToken(std::move(token4), Token::Type::STRING);
        if (token5.type() != Token::Type::COLON)
            throw nts::conf::UnexpectedToken(std::move(token5), Token::Type::COLON);
        if (token6.type() != Token::Type::NUMBER)
            throw nts::conf::UnexpectedToken(std::move(token6), Token::Type::NUMBER);
        if (token7.type() != Token::Type::NEWLINE && token7.type() != Token::Type::END)
            throw nts::conf::UnexpectedToken(std::move(token7), Token::Type::NEWLINE);

        auto p1 = std::stoull(token3.value());
        std::shared_ptr<nts::IComponent> component1;
        Pin* pin1;

        try {
            component1 = circuit.get(token1.value());
            pin1 = &component1->pin(p1);
        } catch (const Circuit::ComponentNotFound&) {
            throw nts::conf::ComponentNotFound(token1.line(), token1.column(), token1.value());
        } catch (const IComponent::InvalidPin&) {
            throw nts::conf::PinOutOfRange(token3.line(), token3.column(), token1.value(), p1);
        }

        auto p2 = std::stoull(token6.value());
        std::shared_ptr<nts::IComponent> component2;
        Pin* pin2;

        try {
            component2 = circuit.get(token4.value());
            pin2 = &component2->pin(p2);
        } catch (const Circuit::ComponentNotFound&) {
            throw nts::conf::ComponentNotFound(token4.line(), token4.column(), token4.value());
        } catch (const IComponent::InvalidPin&) {
            throw nts::conf::PinOutOfRange(token6.line(), token6.column(), token6.value(), p1);
        }

        // Link the pins
        if (pin1->type() == Pin::Type::Output || pin1->type() == Pin::Type::Hybrid) {
            // If pin1 is an output pin2 must be an input or hybrid
            if (pin2->type() == Pin::Type::Output)
                throw nts::conf::InvalidInputPin(token6.line(), token6.column(), token4.value(), p2);

            pin2->link(*pin1);
        } else {
            // If pin1 is an input, pin2 must be an output or hybrid
            if (pin2->type() == Pin::Type::Input)
                throw nts::conf::InvalidOutputPin(token6.line(), token6.column(), token4.value(), p2);

            pin1->link(*pin2);
        }
    }

    static void parseLinks(Lexer& lexer, Circuit& circuit)
    {
        Token token1 = lexer.next();
        Token token2 = lexer.next();
        Token token3 = lexer.next();
        lexer.skipNewlines();

        if (token1.type() != Token::Type::DOT_LINKS)
            throw nts::conf::UnexpectedToken(std::move(token1), Token::Type::DOT_LINKS);
        if (token2.type() != Token::Type::COLON)
            throw nts::conf::UnexpectedToken(std::move(token2), Token::Type::COLON);
        if (token3.type() != Token::Type::NEWLINE && token3.type() != Token::Type::END)
            throw nts::conf::UnexpectedToken(std::move(token3), Token::Type::NEWLINE);

        for (Token token = lexer.peek();
            token.type() != Token::Type::END;
            token = lexer.peek()
        ) {
            parseLink(lexer, circuit);
            lexer.skipNewlines();
        }
    }

    std::unique_ptr<Circuit> parse(const std::string& filename)
    {
        std::unique_ptr<Circuit> circuit = std::make_unique<Circuit>();
        std::unique_ptr<Lexer> lexer;

        try {
            lexer = std::make_unique<Lexer>(std::make_unique<Reader>(filename));
        } catch (const Reader::LoadFailure& e) {
            throw nts::conf::LoadFailure(filename);
        }

        lexer->skipNewlines();
        parseChipsets(*lexer, *circuit);
        parseLinks(*lexer, *circuit);

        if (!circuit->check())
            throw nts::conf::InvalidCircuit();

        return circuit;
    }
}
