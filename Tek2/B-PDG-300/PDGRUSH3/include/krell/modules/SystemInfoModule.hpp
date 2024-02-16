/*
** EPITECH PROJECT, 2024
** SystemInfoModule.hpp
** File description:
** SystemInfoModule.hpp
*/

#pragma once

#include "IModule.hpp"

#include <sys/utsname.h>

namespace Krell {
    class SystemInfoModule : public IModule {
        public:
            SystemInfoModule();
            virtual ~SystemInfoModule() override;

            void update(double deltaTime) override;
            Height render(std::unique_ptr<SFMLDisplay>& display, Width width, HeightOffset offset, bool selected) override;
            Height render(std::unique_ptr<NCursesDisplay>& display, Width width, HeightOffset offset, bool selected) override;

        private:
            // System info
            std::string _time;
            std::string _date;

            char _hostname[HOST_NAME_MAX];
            char _username[LOGIN_NAME_MAX];
            utsname _uname;
            std::string _os;

            // NCurses
            WINDOW *_window;

            // SFML
            sf::RectangleShape _bg;
            sf::Text _systemInfoLabels;
            sf::Text _systemInfoValues;
            sf::Text _timeDate;
    };
}
