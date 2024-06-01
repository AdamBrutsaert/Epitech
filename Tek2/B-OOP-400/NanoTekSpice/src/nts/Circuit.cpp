/*
** EPITECH PROJECT, 2024
** Circuit.cpp
** File description:
** Circuit.cpp
*/

#include "nts/Circuit.hpp"
#include "nts/components/special/InputComponent.hpp"
#include "nts/components/special/ClockComponent.hpp"
#include "nts/components/special/OutputComponent.hpp"

namespace nts {
    void Circuit::add(const std::string& name, std::shared_ptr<IComponent> component)
    {
        if (this->_components.find(name) != this->_components.end())
            throw ComponentAlreadyExists();

        this->_components[name] = component;

        if (std::dynamic_pointer_cast<InputComponent>(component) != nullptr
            || std::dynamic_pointer_cast<ClockComponent>(component) != nullptr
        ) {
            this->_inputs.push_back(name);
            std::sort(this->_inputs.begin(), this->_inputs.end());
        }
        if (std::dynamic_pointer_cast<OutputComponent>(component) != nullptr) {
            this->_outputs.push_back(name);
            std::sort(this->_outputs.begin(), this->_outputs.end());
        }
    }

    std::shared_ptr<IComponent> Circuit::get(const std::string& name)
    {
        auto it = this->_components.find(name);
        if (it == this->_components.end())
            throw ComponentNotFound();
        return it->second;
    }

    std::shared_ptr<IComponent> Circuit::getInput(const std::string& name)
    {
        if (this->_components.find(name) == this->_components.end())
            throw ComponentNotFound();
        if (std::find(this->_inputs.begin(), this->_inputs.end(), name) == this->_inputs.end())
            throw ComponentIsNotAnInput();
        return this->_components[name];
    }

    bool Circuit::check() const
    {
        // Check if there is at least one component
        if (this->_components.empty())
            return false;

        return true;
    }

    void Circuit::simulate()
    {
        for (auto& [_, component] : this->_components)
            component->tick();

        this->_tick++;
    }

    void Circuit::display()
    {
        std::cout << "tick: " << this->_tick << std::endl;

        std::cout << "input(s):" << std::endl;
        for (auto& input : this->_inputs)
            std::cout << "  " << input << ": "
                << this->_components[input]->pin(1).state() << std::endl;

        std::cout << "output(s):" << std::endl;
        for (auto& output : this->_outputs)
            std::cout << "  " << output << ": "
                << this->_components[output]->pin(1).state() << std::endl;
    }

    const std::map<std::string, std::shared_ptr<IComponent>>& Circuit::components() const
    {
        return this->_components;
    }
}
