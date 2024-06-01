/*
** EPITECH PROJECT, 2024
** Pin.cpp
** File description:
** Pin.cpp
*/

#include "nts/components/Pin.hpp"

namespace nts {
    Pin::Pin(Type type)
        : _type(type), _state(Tristate::Undefined)
    {
    }

    void Pin::link(Pin& other)
    {
        other.bind([&]() { this->set(other.state()); });
        this->set(other.state());
    }

    void Pin::bind(const std::function<void()>& func)
    {
        this->_funcs.push_back(func);
    }

    void Pin::set(Tristate state)
    {
        if (state != this->_state) {
            this->_state = state;
            for (auto& func : this->_funcs)
                func();
        }
    }
}
