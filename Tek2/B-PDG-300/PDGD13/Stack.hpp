/*
** EPITECH PROJECT, 2024
** Stack.hpp
** File description:
** Stack.hpp
*/

#pragma once

#include <stack>
#include <string>
#include <exception>

class Stack {
public:
    class Error : public std::exception {
    public:
        Error(std::string const& message);
        ~Error() = default;

        const char* what() const noexcept override;
    private:
        std::string _message;
    };

public:
    Stack() = default;
    ~Stack() = default;

    void push(double value);
    double pop();
    double top() const;

    void add();
    void sub();
    void mul();
    void div();

private:
    std::stack<double> _stack;
};
