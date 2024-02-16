/*
** EPITECH PROJECT, 2024
** Monitor.cpp
** File description:
** Monitor.cpp
*/

#include "krell/core/Monitor.hpp"

#include "krell/modules/SystemInfoModule.hpp"
#include "krell/modules/CpuModule.hpp"
#include "krell/modules/RamModule.hpp"
#include "krell/modules/BatteryModule.hpp"

namespace Krell {
    Monitor::Monitor(Configuration&& configuration)
        : _config(std::move(configuration)), _selectedModule(0)
    {
        for (auto& module : this->_config.modules)
            this->_modules.push_back(std::move(module));
    }

    void Monitor::add(std::unique_ptr<IModule>&& module)
    {
        this->_modules.push_back(std::move(module));
    }

    void Monitor::run()
    {
        switch (this->_config.displayMode) {
        case DisplayMode::NCURSES: {
            auto display = std::make_unique<NCursesDisplay>();
            this->_bindHandlers(*display);
            this->_run(std::move(display));
            break;
        }
        case DisplayMode::SFML: {
            auto display = std::make_unique<SFMLDisplay>();
            this->_bindHandlers(*display);
            this->_run(std::move(display));
            break;
        }
        default:
            break;
        }
    }

    void Monitor::_update(double deltaTime) const
    {
        for (auto& module : this->_modules)
            module->update(deltaTime);
    }

    void Monitor::_bindHandlers(IDisplay &display)
    {
        display.setOnKeyReleased([&display, this](sf::Keyboard::Key key) {
            if (key == sf::Keyboard::Escape) {
                display.close();
            } else if (key == sf::Keyboard::Tab) {
                this->_selectedModule = (this->_selectedModule + 1) % this->_modules.size();
            } else if (key == sf::Keyboard::Up) {
                if (this->_selectedModule == 0)
                    return;

                std::swap(this->_modules[this->_selectedModule], this->_modules[this->_selectedModule - 1]);
                this->_selectedModule--;
            } else if (key == sf::Keyboard::Down) {
                if (this->_selectedModule + 1 == this->_modules.size())
                    return;

                std::swap(this->_modules[this->_selectedModule], this->_modules[this->_selectedModule + 1]);
                this->_selectedModule++;
            } else if (key == sf::Keyboard::D) {
                if (this->_modules.size() == 0)
                    return;

                this->_modules.erase(this->_modules.begin() + this->_selectedModule);
                this->_selectedModule = std::min<std::size_t>(this->_selectedModule, this->_modules.size() - 1);
                display.forceClear();
            } else if (key == sf::Keyboard::S) {
                this->add(std::make_unique<SystemInfoModule>());
            } else if (key == sf::Keyboard::C) {
                this->add(std::make_unique<CpuModule>());
            } else if (key == sf::Keyboard::R) {
                this->add(std::make_unique<RamModule>());
            } else if (key == sf::Keyboard::B) {
                this->add(std::make_unique<BatteryModule>());
            }
        });
    }
}
