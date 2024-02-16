/*
** EPITECH PROJECT, 2024
** Stack.cpp
** File description:
** Stack.cpp
*/

#include "Stack.hpp"

Stack::Error::Error(std::string const& message)
    : _message(message)
{
}

const char* Stack::Error::what() const noexcept
{
    return this->_message.c_str();
}

void Stack::push(double value)
{
    this->_stack.push(value);
}

double Stack::pop()
{
    if (this->_stack.empty())
        throw Stack::Error("Empty stack");

    double value = this->_stack.top();
    this->_stack.pop();
    return value;
}

double Stack::top() const
{
    if (this->_stack.empty())
        throw Stack::Error("Empty stack");

    return this->_stack.top();
}

void Stack::add()
{
    if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");

    double a = this->pop();
    double b = this->pop();
    this->push(a + b);
}

void Stack::sub()
{
    if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");

    double a = this->pop();
    double b = this->pop();
    this->push(a - b);
}

void Stack::mul()
{
    if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");

    double a = this->pop();
    double b = this->pop();
    this->push(a * b);
}

void Stack::div()
{
    if (this->_stack.size() < 2)
        throw Stack::Error("Not enough operands");

    double a = this->pop();
    double b = this->pop();
    this->push(a / b);
}
