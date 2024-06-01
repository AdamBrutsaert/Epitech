/*
** EPITECH PROJECT, 2024
** ComponentFactory.hpp
** File description:
** ComponentFactory.hpp
*/

#pragma once

#include "IComponent.hpp"

#include <memory>
#include <map>
#include <functional>

namespace nts {
    class ComponentFactory {
    public:
        class InvalidComponentType : public std::exception {};

    public:
        static std::unique_ptr<nts::IComponent> createComponent(const std::string& type);

    private:
        static std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> _components;
    };
}
