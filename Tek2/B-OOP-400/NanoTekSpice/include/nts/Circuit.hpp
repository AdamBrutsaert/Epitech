/*
** EPITECH PROJECT, 2024
** Circuit.hpp
** File description:
** Circuit.hpp
*/

#pragma once

#include "components/IComponent.hpp"

#include <map>
#include <memory>
#include <string>

namespace nts {
    class Circuit {
    public:
        class ComponentNotFound : public std::exception {};
        class ComponentAlreadyExists : public std::exception {};
        class ComponentIsNotAnInput : public std::exception {};

    public:
        Circuit() = default;
        Circuit(const Circuit& other) = delete;
        Circuit(Circuit&& other) = default;
        Circuit& operator=(const Circuit& other) = delete;
        Circuit& operator=(Circuit&& other) = default;
        ~Circuit() = default;

        void add(const std::string& name, std::shared_ptr<IComponent> component);
        std::shared_ptr<IComponent> get(const std::string& name);
        std::shared_ptr<IComponent> getInput(const std::string& name);

        bool check() const;

        void simulate();
        void display();
        void force_update_outputs();

        const std::map<std::string, std::shared_ptr<IComponent>>& components() const;

    private:
        std::size_t _tick = 0;
        std::vector<std::string> _inputs;
        std::vector<std::string> _outputs;
        std::map<std::string, std::shared_ptr<IComponent>> _components;
    };
}
