/*
** EPITECH PROJECT, 2024
** Pin.hpp
** File description:
** Pin.hpp
*/

#pragma once

#include "Tristate.hpp"

#include <functional>
#include <vector>

namespace nts {
    class Pin {
    public:
        enum class Type {
            Input,
            Output,
            Hybrid,
        };

    public:
        Pin(Type type);
        Pin(const Pin& other) = delete;
        Pin(Pin&& other) = default;
        Pin& operator=(const Pin& other) = delete;
        Pin& operator=(Pin&& other) = default;
        ~Pin() = default;

        inline Tristate state() const { return this->_state; };
        inline Type type() const { return this->_type; }

        void set(Tristate state);
        void link(Pin& other);
        void bind(const std::function<void()>& func);

    private:
        Type _type;
        Tristate _state;
        std::vector<std::function<void()>> _funcs;
    };
}
