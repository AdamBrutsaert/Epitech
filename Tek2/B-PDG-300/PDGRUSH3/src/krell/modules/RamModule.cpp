/*
** EPITECH PROJECT, 2024
** CpuModule.cpp
** File description:
** CpuModule.cpp
*/

#include "krell/modules/RamModule.hpp"
#include "krell/core/KernelParser.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace Krell {
    RamModule::RamModule()
        :  _window(nullptr)
    {
        this->_rectangle.setFillColor(sf::Color(47, 35, 148));
        this->_bgRectangle.setFillColor(sf::Color(0, 0, 0, 0));
        this->_elapsedTime = 1;
        this->_memoryUsage = 0;
        this->_freeMemory = 0;
        this->_totalMemory = 0;
    }

    RamModule::~RamModule()
    {
        delwin(this->_window);
    }

    void RamModule::update(double deltaTime)
    {
        this->_elapsedTime += deltaTime;
        if (this->_elapsedTime < 0.75) {
            return;
        }
        this->_elapsedTime = 0;

        auto map  = Krell::Kernel::parseInfo("/proc/meminfo");
        unsigned long total = std::stod(map->at("MemTotal").substr(0, map->at("MemTotal").size() - 3));
        unsigned long available = std::stod(map->at("MemAvailable").substr(0, map->at("MemAvailable").size() - 3));
        this->_totalMemory = total;
        this->_freeMemory = available;
        this->_memoryUsage = (double)(total - available) / total * 100;
    }

    Height RamModule::render(std::unique_ptr<SFMLDisplay>& display, Width width, HeightOffset offset, bool selected)
    {
        float centerHeight = display->getWidth() / 2.0 - this->_text.getGlobalBounds().width / 2;
        float centerWidth = offset + this->_rectangle.getSize().y / 2.0 - this->_text.getGlobalBounds().height / 2;

        this->_rectangle.setSize(sf::Vector2f(width * (this->_memoryUsage / 100), 125));
        this->_bgRectangle.setSize(sf::Vector2f(width, 125));
        this->_rectangle.setPosition(0, offset);
        this->_bgRectangle.setPosition(0, offset);
        this->_bgRectangle.setOutlineColor(sf::Color::Red);
        this->_bgRectangle.setOutlineThickness(selected ? -2 : 0);
        display->getRenderTarget().draw(this->_rectangle);
        display->getRenderTarget().draw(this->_bgRectangle);

        this->_text.setFont(display->getFont());
        this->_text.setString("RAM: " + std::to_string(this->_memoryUsage).substr(0, 4) + "%");
        this->_text.setPosition(centerHeight, centerWidth);
        display->getRenderTarget().draw(this->_text);
        return 125;
    }

    void RamModule::createRAMLineChart(Width width, HeightOffset offset)
    {
        int padding = 5;
        int innerWidth = width - 2 * padding;
        int greenDots = innerWidth / 2;
        int yellowDots = innerWidth / 4;
        int redDots = innerWidth - greenDots - yellowDots;
        int lastPipe = this->_memoryUsage / 100 * innerWidth; 

        mvwprintw(this->_window, offset, padding - 1, "[");

        // Green dots
        wattron(this->_window, A_BOLD);
        wattron(this->_window, COLOR_PAIR(1));
        for (int i = 0; i < greenDots; i++) {
            if (i < lastPipe) {
                mvwprintw(this->_window, offset, padding + i, "|");
            } else {
                mvwprintw(this->_window, offset, padding + i, ".");
            }
        }
        wattroff(this->_window, COLOR_PAIR(1));
        wattroff(this->_window, A_BOLD);

        // Green dots
        wattron(this->_window, A_BOLD);
        wattron(this->_window, COLOR_PAIR(4));
        for (int i = 0; i < yellowDots; i++) {
            if (greenDots + i < lastPipe) {
                mvwprintw(this->_window, offset, padding + greenDots + i, "|");
            } else {
                mvwprintw(this->_window, offset, padding + greenDots + i, ".");
            }
        }
        wattroff(this->_window, COLOR_PAIR(4));
        wattroff(this->_window, A_BOLD);

        // Red dots
        wattron(this->_window, A_BOLD);
        wattron(this->_window, COLOR_PAIR(2));
        for (int i = 0; i < redDots; i++) {
            if (greenDots + yellowDots + i < lastPipe) {
                mvwprintw(this->_window, offset, padding + greenDots + yellowDots + i, "|");
            } else {
                mvwprintw(this->_window, offset, padding + greenDots + yellowDots + i, ".");
            }
        }
        wattroff(this->_window, COLOR_PAIR(2));
        wattroff(this->_window, A_BOLD);

        // Percentages
        mvwprintw(this->_window, offset, padding + 3, " %0.f %% ", this->_memoryUsage);
    
        mvwprintw(this->_window, offset, width - padding, "]");
    }

    Height RamModule::render(std::unique_ptr<NCursesDisplay>& display, Width width, HeightOffset offset, bool selected)
    {
        wclear(this->_window);
        delwin(this->_window);
        this->_window = newwin(6, width, offset, 0);

        if (selected) wattron(this->_window, COLOR_PAIR(2));
        box(this->_window, 0, 0);
        mvwprintw(this->_window, 0, 3, " RAM info ");
        if (selected) wattroff(this->_window, COLOR_PAIR(2));

        this->createRAMLineChart(width, 2);

        // RAM Usage: used / total, free
        std::string str = " RAM Usage: " + std::to_string(this->_totalMemory - this->_freeMemory) + " / " + std::to_string(this->_totalMemory) + " KB, " + std::to_string(this->_freeMemory) + " KB free";
        mvwprintw(this->_window, 3, 5, "%s", str.c_str());

        wrefresh(this->_window);
        return 6;
    }
};
