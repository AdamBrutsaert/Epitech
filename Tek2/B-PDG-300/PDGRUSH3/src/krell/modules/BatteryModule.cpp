/*
** EPITECH PROJECT, 2024
** BatteryModule.cpp
** File description:
** BatteryModule.cpp
*/

#include "krell/modules/BatteryModule.hpp"

#include <fstream>
#include <iostream>

namespace Krell {
    BatteryModule::BatteryModule()
    {
        this->_battery = std::nullopt;
        this->_batteryStatus = "Unknown";
        this->_window = nullptr;
        this->_rectangle.setFillColor(sf::Color(49, 110, 48));
        this->_bgRectangle.setFillColor(sf::Color(0, 0, 0, 0));
        this->_texture.loadFromFile("assets/charging_indicator.png");
    }

    BatteryModule::~BatteryModule()
    {
        delwin(this->_window);
    }

    void BatteryModule::update(double deltaTime)
    {
        std::ifstream file;
        this->_batteryStatus = "Unknown";

        for (uint64_t i = 0; i < 5; i++) {
            file.open("/sys/class/power_supply/BAT" + std::to_string(i) + "/capacity");

            if (!!file)
                break;
        }

        if (!file) {
            this->_battery = std::nullopt;
            return;
        }

        std::string line;
        if (!std::getline(file, line)) {
            this->_battery = std::nullopt;
            return;
        }

        this->_battery = std::stoull(line);

        // charging indicator
        std::ifstream chargingFile;
        for (uint64_t i = 0; i < 5; i++) {
            chargingFile.open("/sys/class/power_supply/BAT" + std::to_string(i) + "/status");

            if (!!chargingFile)
                break;
        }

        if (!chargingFile) {
            this->_batteryStatus = "Unknown";
            return;
        }

        if (!std::getline(chargingFile, this->_batteryStatus)) {
            this->_batteryStatus = "Unknown";
            return;
        }
    }

    Height BatteryModule::render(std::unique_ptr<SFMLDisplay>& display, Width width, HeightOffset offset, bool selected)
    {
        float centerHeight = display->getWidth() / 2.0 - this->_text.getGlobalBounds().width / 2;
        float centerWidth = offset + this->_rectangle.getSize().y / 2.0 - this->_text.getGlobalBounds().height / 2;

        this->_rectangle.setSize(sf::Vector2f(width * (this->_battery.value_or(0) / 100.0f), 30));
        this->_bgRectangle.setSize(sf::Vector2f(width, 30));
        this->_rectangle.setPosition(0, offset);
        this->_bgRectangle.setPosition(0, offset);
        this->_bgRectangle.setOutlineColor(sf::Color::Red);
        this->_bgRectangle.setOutlineThickness(selected ? -2 : 0);
        display->getRenderTarget().draw(this->_rectangle);
        display->getRenderTarget().draw(this->_bgRectangle);

        this->_text.setFont(display->getFont());
        this->_text.setString(std::to_string(this->_battery.value_or(0)) + "%");
        this->_text.setPosition(centerHeight, this->_rectangle.getPosition().y + 5);
        this->_text.setCharacterSize(12);
        display->getRenderTarget().draw(this->_text);

        if (this->_batteryStatus == "Charging" || this->_batteryStatus == "Full") {
            this->_sprite.setTexture(this->_texture);
            this->_sprite.setPosition(centerHeight + 35, this->_rectangle.getPosition().y + 5);
            this->_sprite.setScale(0.03, 0.03);
            display->getRenderTarget().draw(this->_sprite);
        }

        return 30;
    }

    void BatteryModule::createBatteryLineChart(Width width, HeightOffset offset, double percentage, const std::string& name)
    {
        // Measuring
        Width padding = 5;
        Width innerWidth = width - 2 * padding;

        // Dots
        Width greenDots = innerWidth / 2;
        Width yellowDots = greenDots + innerWidth / 4;
        Width redDots = innerWidth;
        Width pipes = percentage / 100.0f * innerWidth;

        // Print
        mvwprintw(this->_window, offset, padding - 1, "[");

        // Green dots
        wattron(this->_window, A_BOLD);
        wattron(this->_window, COLOR_PAIR(1));
        for (int i = 0; i < greenDots; i++) {
            mvwprintw(
                this->_window,
                offset,
                padding + i,
                i < pipes ? "|" : "."
            );
        }
        wattroff(this->_window, COLOR_PAIR(1));
        wattroff(this->_window, A_BOLD);

        // Yellow dots
        wattron(this->_window, A_BOLD);
        wattron(this->_window, COLOR_PAIR(4));
        for (int i = greenDots; i < yellowDots; i++) {
            mvwprintw(
                this->_window,
                offset,
                padding + i,
                i < pipes ? "|" : "."
            );
        }
        wattroff(this->_window, COLOR_PAIR(4));
        wattroff(this->_window, A_BOLD);

        // Red dots
        wattron(this->_window, A_BOLD);
        wattron(this->_window, COLOR_PAIR(2));
        for (int i = yellowDots; i < redDots; i++) {
            mvwprintw(
                this->_window,
                offset,
                padding + i,
                i < pipes ? "|" : "."
            );
        }
        wattroff(this->_window, COLOR_PAIR(2));
        wattroff(this->_window, A_BOLD);

        mvwprintw(this->_window, offset, width - padding, "]");

        // Percentages & core
        mvwprintw(this->_window, offset, padding + 3, " %0.f %% ", percentage);
        mvwprintw(this->_window, offset, width - padding - 5 - name.length(), " %s ", name.c_str());
    }

    Height BatteryModule::render(std::unique_ptr<NCursesDisplay>& display, Width width, HeightOffset offset, bool selected)
    {
        uint64_t battery = this->_battery.value_or(0);

        wclear(this->_window);
        delwin(this->_window);
        this->_window = newwin(5, width, offset, 0);

        if (selected) wattron(this->_window, COLOR_PAIR(2));
        box(this->_window, 0, 0);
        mvwprintw(this->_window, 0, 3, " Battery Info ");
        if (selected) wattroff(this->_window, COLOR_PAIR(2));

        createBatteryLineChart(width, 2, battery, this->_batteryStatus);

        wrefresh(this->_window);

        return 5;
    }
}
