/*
** EPITECH PROJECT, 2024
** Configuration.hpp
** File description:
** Configuration.hpp
*/

#pragma once

#include "krell/modules/IModule.hpp"
#include <string>
#include <vector>

namespace Krell {
    enum class DisplayMode {
        UNKNOWN = 0,
        NCURSES = 1,
        SFML = 2,
    };

    struct Configuration {
        Configuration() = default;
        Configuration(const Configuration &other) = delete;
        Configuration(Configuration &&other) = default;
        Configuration& operator=(const Configuration &other) = delete;
        Configuration& operator=(Configuration &&other) = default;

        std::string configFile = "config.krell";
        DisplayMode displayMode = DisplayMode::NCURSES;
        std::vector<std::unique_ptr<Krell::IModule>> modules;
    };

    DisplayMode getDisplayModeFromString(const std::string &str);

    namespace Parser {
        void parseFlags(int argc, char **argv, Configuration &config);
        bool parseFile(Configuration &config);
    };
};
