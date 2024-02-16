/*
** EPITECH PROJECT, 2024
** CpuModule.cpp
** File description:
** CpuModule.cpp
*/

#include "krell/modules/CpuModule.hpp"
#include "krell/core/KernelParser.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>

namespace Krell {
    CpuModule::CpuModule()
    {
        this->_elapsedTime = 0;

        this->_physicalCores = 0;
        this->_virtualCores = 0;
        this->_cpuInfo = {0, 0, 0};

        this->_rectangle.setFillColor(sf::Color(49, 110, 48));
        this->_bgRectangle.setFillColor(sf::Color(0, 0, 0, 0));

        this->_window = nullptr;

        this->computeCpuCoreCount();
        this->computeCpuUsage();
    }

    CpuModule::~CpuModule()
    {
        delwin(this->_window);
    }

    void CpuModule::computeCpuCoreCount()
    {
        auto map = Krell::Kernel::parseCategorizedInfo("/proc/cpuinfo", "processor");
        std::set<std::string> physicalIds;

        for (auto& [_, core]: *map) {
            if (core.contains("coreid"))
                physicalIds.insert(core["coreid"]);
        }

        this->_physicalCores = physicalIds.size();
        this->_virtualCores = map->size();
    }

    // Explanation
    // https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
    static std::tuple<unsigned long long, unsigned long long> parseCpuLine(const std::string& line)
    {
        std::istringstream iss(line);

        std::string cpu;
        unsigned long long user;
        unsigned long long nice;
        unsigned long long system;
        unsigned long long idle;
        unsigned long long iowait;
        unsigned long long irq;
        unsigned long long softirq;
        unsigned long long steal;
        unsigned long long guest;
        unsigned long long guest_nice;

        if (!(iss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice))
            return {0, 0};

        unsigned long long currentIdle = idle + iowait;
        unsigned long long currentNonIdle = user + nice + system + irq + softirq + steal;
        unsigned long long currentTotal = currentIdle + currentNonIdle;

        return {currentIdle, currentTotal};
    }

    void CpuModule::computeCpuUsage()
    {
        std::ifstream file("/proc/stat");
        std::string line;

        // Parse first line
        if (!std::getline(file, line))
            return;

        auto [currentIdle, currentTotal] = parseCpuLine(line);

        unsigned long long totald = currentTotal - this->_cpuInfo.prevTotal;
        unsigned long long idled = currentIdle - this->_cpuInfo.prevIdle;

        if (totald != 0) {
            this->_cpuInfo.usage = (totald - idled) * 100.0 / totald;
            this->_cpuInfo.prevTotal = currentTotal;
            this->_cpuInfo.prevIdle = currentIdle;
        }

        // Parse <virtual cores> lines
        this->_coreInfos.resize(this->_virtualCores);
        for (int i = 0; i < this->_virtualCores; i++) {
            if (!std::getline(file, line))
                return;

            auto [currentIdle, currentTotal] = parseCpuLine(line);

            unsigned long long totald = currentTotal - this->_coreInfos[i].prevTotal;
            unsigned long long idled = currentIdle - this->_coreInfos[i].prevIdle;

            if (totald == 0)
                continue;

            this->_coreInfos[i].usage = (totald - idled) * 100.0 / totald;
            this->_coreInfos[i].prevTotal = currentTotal;
            this->_coreInfos[i].prevIdle = currentIdle;
        }
    }

    void CpuModule::update(double deltaTime)
    {
        this->_elapsedTime += deltaTime;
        if (this->_elapsedTime < 0.500)
            return;
        this->_elapsedTime = 0;

        this->computeCpuCoreCount();
        this->computeCpuUsage();
    }

    Height CpuModule::render(std::unique_ptr<SFMLDisplay>& display, Width width, HeightOffset offset, bool selected)
    {
        float centerHeight = display->getWidth() / 2.0 - this->_text.getGlobalBounds().width / 2;
        float centerWidth = offset + this->_rectangle.getSize().y / 2.0 - this->_text.getGlobalBounds().height / 2;

        this->_rectangle.setSize(sf::Vector2f(width * (this->_cpuInfo.usage / 100), 180));
        this->_bgRectangle.setSize(sf::Vector2f(width, 180));
        this->_rectangle.setPosition(0, offset);
        this->_bgRectangle.setPosition(0, offset);
        this->_bgRectangle.setOutlineColor(sf::Color::Red);
        this->_bgRectangle.setOutlineThickness(selected ? -2 : 0);
        display->getRenderTarget().draw(this->_rectangle);
        display->getRenderTarget().draw(this->_bgRectangle);

        this->_text.setFont(display->getFont());
        this->_text.setString("CPU: " + std::to_string(this->_cpuInfo.usage).substr(0, 4) + "%");
        this->_text.setCharacterSize(30);
        this->_text.setFillColor(sf::Color(255, 255, 255, 255));
        this->_text.setPosition(centerHeight, centerWidth);

        // Cores rectangles display
        for (int i = 0; i < this->_coreInfos.size(); i++) {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f((float)width / this->_coreInfos.size(), 180.0 * this->_coreInfos[i].usage / 100));
            rectangle.setPosition((float)width / this->_coreInfos.size() * i, offset + 180 - rectangle.getSize().y);
            rectangle.setFillColor(sf::Color(46, 201, 88));
            display->getRenderTarget().draw(rectangle);
        }

        display->getRenderTarget().draw(this->_text);

        return 180;
    }

    void CpuModule::printCoreLine(Width width, HeightOffset offset, double percentage, const std::string& name)
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

    Height CpuModule::render(std::unique_ptr<NCursesDisplay>& display, Width width, HeightOffset offset, bool selected)
    {
        wclear(this->_window);
        delwin(this->_window);
        this->_window = newwin(this->_virtualCores + 7, width, offset, 0);

        if (selected) wattron(this->_window, COLOR_PAIR(2));
        box(this->_window, 0, 0);
        mvwprintw(this->_window, 0, 3, " CPU info ");
        if (selected) wattroff(this->_window, COLOR_PAIR(2));

        // Total
        this->printCoreLine(width, 2, this->_cpuInfo.usage, "Total");
        mvwprintw(this->_window, 3, 5, " Physical: ");
        wattron(this->_window, A_BOLD);
        wattron(this->_window, COLOR_PAIR(4));
        mvwprintw(this->_window, 3, 16, "%zu", this->_physicalCores);
        wattroff(this->_window, COLOR_PAIR(4));
        wattroff(this->_window, A_BOLD);
        mvwprintw(this->_window, 3, 17, ", Virtual: ");
        wattron(this->_window, A_BOLD);
        wattron(this->_window, COLOR_PAIR(4));
        mvwprintw(this->_window, 3, 28, "%zu", this->_virtualCores);
        wattroff(this->_window, COLOR_PAIR(4));
        wattroff(this->_window, A_BOLD);

        for (int i = 0; i < this->_coreInfos.size(); i++)
            this->printCoreLine(width, 5 + i, this->_coreInfos[i].usage, "Core " + std::to_string(i));

        wrefresh(this->_window);
        return this->_virtualCores + 7;
    }
};
