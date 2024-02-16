/*
** EPITECH PROJECT, 2024
** KernelParser.cpp
** File description:
** KernelParser.cpp
*/

#include "krell/core/KernelParser.hpp"

#include <fstream>
#include <algorithm>

std::unique_ptr<std::map<std::string, std::string>> Krell::Kernel::parseInfo(std::string location)
{
    auto map = std::make_unique<std::map<std::string, std::string>>();
    std::ifstream file(location);

    if (!file.is_open() || !file.good())
        return map;
    
    std::string line;

    while (std::getline(file, line)) {
        auto pos = line.find(":");
        auto key = line.substr(0, pos);
        auto value = line.substr(pos + 1);

        if (key.empty() || value.empty())
            continue;
        key.erase(std::remove_if(key.begin(), key.end(), isspace), key.end());
        value.erase(0, value.find_first_not_of(' '));
        map->insert(std::make_pair(key, value));
    }

    file.close();
    return map;
}

std::unique_ptr<std::map<std::string, std::string>> Krell::Kernel::parsePropertyInfo(std::string location)
{
    std::ifstream file(location);
    auto map = std::make_unique<std::map<std::string, std::string>>();

    if (!file.is_open() || !file.good())
        return map;

    std::string line;

    while (std::getline(file, line)) {
        auto pos = line.find("=");
        auto key = line.substr(0, pos);
        auto value = line.substr(pos + 1);

        if (key.empty() || value.empty())
            continue;
        key.erase(std::remove_if(key.begin(), key.end(), isspace), key.end());
        value.erase(0, value.find_first_not_of(' '));
        value.erase(value.find_last_not_of(' ') + 1);
        value.erase(value.find_last_not_of('"') + 1);
        value.erase(0, value.find_first_not_of('"'));
        map->insert(std::make_pair(key, value));
    }
    file.close();
    return map;
}

std::unique_ptr<std::map<std::string, std::map<std::string, std::string>>> Krell::Kernel::parseCategorizedInfo(std::string location, std::string categoryKey)
{
    std::ifstream file(location);
    auto map = std::make_unique<std::map<std::string, std::map<std::string, std::string>>>();

    if (!file.is_open() || !file.good())
        return map;
    
    std::string line;
    std::string category;

    while (std::getline(file, line)) {
        auto pos = line.find(":");
        auto key = line.substr(0, pos);
        auto value = line.substr(pos + 1);

        if (key.empty() || value.empty())
            continue;
        key.erase(std::remove_if(key.begin(), key.end(), isspace), key.end());
        value.erase(0, value.find_first_not_of(' '));
        
        if (key == categoryKey) {
            category = value;
            map->insert(std::make_pair(category, std::map<std::string, std::string>()));
        } else {
            map->at(category).insert(std::make_pair(key, value));
        }
    }

    file.close();
    return map;
}

bool Krell::Kernel::parseBoolFile(std::string location)
{
    std::ifstream file(location);

    if (!file.is_open() || !file.good())
        return false;
    
    std::string line;

    std::getline(file, line);
    file.close();
    return line == "1";
}
