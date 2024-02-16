/*
** EPITECH PROJECT, 2024
** Monitor.hpp
** File description:
** Monitor.hpp
*/

#pragma once

#include "Configuration.hpp"
#include "../modules/IModule.hpp"

#include <vector>

namespace Krell {
    class Monitor final {
    public:
        Monitor(Configuration&& configuration);
        Monitor(const Monitor& other) = delete;
        Monitor(Monitor&& other) = delete;
        Monitor& operator=(const Monitor& other) = delete;
        Monitor& operator=(Monitor&& other) = delete;
        ~Monitor() = default;

        void add(std::unique_ptr<IModule>&& module);
        void run();

    private:
        Configuration _config;
        std::vector<std::unique_ptr<IModule>> _modules;
        std::size_t _selectedModule;

    private:
        template<typename T>
        void _render(std::unique_ptr<T>& display) const;
        void _update(double deltaTime) const;

        template<typename T>
        void _run(std::unique_ptr<T>&& display);
        void _bindHandlers(IDisplay &display);
    };

    template<typename T>
    void Monitor::_render(std::unique_ptr<T>& display) const
    {
        HeightOffset offset = 0;
        Width width = display->getWidth();

        display->clear();
        for (size_t i = 0; i < this->_modules.size(); i++)
            offset += this->_modules[i]->render(display, width, offset, i == this->_selectedModule);
        display->display();
    }

    template<typename T>
    void Monitor::_run(std::unique_ptr<T>&& display)
    {
        sf::Clock clock;

        while (!display->shouldClose()) {
            double deltaTime = clock.restart().asSeconds();

            display->pollEvents();
            this->_update(deltaTime);
            this->_render(display);
        }
    }
}
