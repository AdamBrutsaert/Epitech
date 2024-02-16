/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main.cpp
*/

#include "krell/core/Configuration.hpp"
#include "krell/core/Monitor.hpp"
#include "krell/modules/CpuModule.hpp"
#include "krell/modules/RamModule.hpp"
#include "krell/modules/SystemInfoModule.hpp"
#include "krell/modules/BatteryModule.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    Krell::Configuration config;
    Krell::Parser::parseFlags(argc, argv, config);

    if (!Krell::Parser::parseFile(config)) {
        std::cerr << "Failed to parse configuration file." << std::endl;
        std::cerr << "Using default configuration." << std::endl;
        config.modules.push_back(std::make_unique<Krell::BatteryModule>());
        config.modules.push_back(std::make_unique<Krell::SystemInfoModule>());
        config.modules.push_back(std::make_unique<Krell::CpuModule>());
        config.modules.push_back(std::make_unique<Krell::RamModule>());
    }

    Krell::Monitor monitor(std::move(config));
    monitor.run();
    return 0;
}
