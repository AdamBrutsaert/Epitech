/*
** EPITECH PROJECT, 2024
** SystemInfoModule.cpp
** File description:
** SystemInfoModule.cpp
*/

#include "krell/modules/SystemInfoModule.hpp"
#include "krell/core/KernelParser.hpp"

namespace Krell {
    SystemInfoModule::SystemInfoModule()
    {
        this->_time = "";
        this->_date = "";
        this->_hostname[0] = '\0';
        this->_username[0] = '\0';
        this->_uname.version[0] = '\0';
        this->_uname.machine[0] = '\0';
        this->_uname.nodename[0] = '\0';
        this->_uname.domainname[0] = '\0';
        this->_uname.sysname[0] = '\0';
        this->_uname.release[0] = '\0';
        this->_os = "";
        this->_window = nullptr;

        this->_bg.setFillColor(sf::Color(69, 51, 79));

        this->_systemInfoLabels.setFillColor(sf::Color::White);
        this->_systemInfoValues.setFillColor(sf::Color::White);
        this->_timeDate.setFillColor(sf::Color::White);
    }

    SystemInfoModule::~SystemInfoModule()
    {
        delwin(this->_window);
    }

    void SystemInfoModule::update([[maybe_unused]] double deltaTime)
    {
        const auto time = std::time(0);
        const auto localTime = std::localtime(&time);

        this->_date = (std::to_string(localTime->tm_year + 1900) + "/"
            + (localTime->tm_mon + 1 < 10 ? std::string("0") : std::string("")) + std::to_string(localTime->tm_mon + 1) + "/"
            + (localTime->tm_mday + 1 < 10 ? std::string("0") : std::string("")) + std::to_string(localTime->tm_mday));

        this->_time = (localTime->tm_hour < 10 ? std::string("0") : std::string("")) + std::to_string(localTime->tm_hour)
            + ":" + (localTime->tm_min < 10 ? std::string("0") : std::string("")) + std::to_string(localTime->tm_min)
            + ":" + (localTime->tm_sec < 10 ? std::string("0") : std::string("")) + std::to_string(localTime->tm_sec);

        gethostname(this->_hostname, HOST_NAME_MAX);
        getlogin_r(this->_username, LOGIN_NAME_MAX);
        uname(&this->_uname);
        auto infos = Krell::Kernel::parsePropertyInfo("/etc/os-release");
        this->_os = infos->at("PRETTY_NAME");
    }

    Height SystemInfoModule::render(std::unique_ptr<SFMLDisplay>& display, Width width, HeightOffset offset, bool selected)
    {
        // Background
        this->_bg.setSize(sf::Vector2f(width, 110));
        this->_bg.setPosition(0, offset);
        this->_bg.setOutlineColor(sf::Color::Red);
        this->_bg.setOutlineThickness(selected ? -2 : 0);

        // System info labels
        this->_systemInfoLabels.setFont(display->getFont());
        this->_systemInfoLabels.setCharacterSize(16);
        this->_systemInfoLabels.setPosition(sf::Vector2f(10, offset + 10));
        this->_systemInfoLabels.setString(
            std::string("Username: ")
            + std::string("\nHostname: ")
            + std::string("\nOp. sys: ")
            + std::string("\nKernel: ")
        );

        // System info values
        this->_systemInfoValues.setFont(display->getFont());
        this->_systemInfoValues.setCharacterSize(16);
        this->_systemInfoValues.setPosition(sf::Vector2f(this->_systemInfoLabels.getGlobalBounds().width + 10, offset + 10));
        this->_systemInfoValues.setString(
            std::string(this->_username)
            + "\n" + std::string(this->_hostname)
            + "\n" + std::string(this->_os)
            + "\n" + std::string(this->_uname.sysname)
        );

        // Time and date
        this->_timeDate.setFont(display->getFont());
        this->_timeDate.setCharacterSize(16);
        this->_timeDate.setPosition(sf::Vector2f(width - 105, offset + 32));
        this->_timeDate.setString("       " + this->_time + "\n" + this->_date);

        display->getRenderTarget().draw(this->_bg);
        display->getRenderTarget().draw(this->_systemInfoLabels);
        display->getRenderTarget().draw(this->_systemInfoValues);
        display->getRenderTarget().draw(this->_timeDate);

        return this->_bg.getSize().y;
    }

    Height SystemInfoModule::render(std::unique_ptr<NCursesDisplay>& display, Width width, HeightOffset offset, bool selected)
    {
        wclear(this->_window);
        delwin(this->_window);
        this->_window = newwin(8, width, offset, 0);

        if (selected) wattron(this->_window, COLOR_PAIR(2));
        box(this->_window, 0, 0);
        mvwprintw(this->_window, 0, 3, " System Info ");
        if (selected) wattroff(this->_window, COLOR_PAIR(2));

        wattron(this->_window, A_UNDERLINE);
        mvwprintw(this->_window, 2, 3, "Username:");
        mvwprintw(this->_window, 3, 3, "Hostname:");
        mvwprintw(this->_window, 4, 3, "Op. Sys.:");
        mvwprintw(this->_window, 5, 3, "Kernel:");
        wattroff(this->_window, A_UNDERLINE);

        wattron(this->_window, A_BOLD);
        wattron(this->_window, COLOR_PAIR(1));
        mvwprintw(this->_window, 3, 12, " %s", this->_hostname);
        mvwprintw(this->_window, 4, 12, " %s", this->_os.c_str());
        mvwprintw(this->_window, 5, 12, " %s", this->_uname.release);
        mvwprintw(this->_window, 2, 12, " %s", this->_username);
        wattroff(this->_window, COLOR_PAIR(1));
        wattroff(this->_window, A_BOLD);

        mvwprintw(this->_window, 3, width - 3 - this->_date.length(), "%s", this->_date.c_str());
        mvwprintw(this->_window, 4, width - 3 - this->_time.length(), "%s", this->_time.c_str());

        wrefresh(this->_window);
        return 8;
    }
}
