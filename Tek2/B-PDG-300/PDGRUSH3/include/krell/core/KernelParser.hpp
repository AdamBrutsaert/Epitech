/*
** EPITECH PROJECT, 2024
** KernelParser.hpp
** File description:
** KernelParser.hpp
*/

#pragma once

#include <memory>
#include <map>
#include <string>

namespace Krell {
    namespace Kernel {

        /// @brief Parse infos from a file (usually /proc/meminfo) in a key:value format.
        /// @param location the location of the file to parse
        /// @return a map containing the parsed infos
        std::unique_ptr<std::map<std::string, std::string>> parseInfo(std::string location);

        /// @brief Parse infos from a file (usually /etc/os-release) in a key=value format.
        /// @param location the location of the file to parse
        /// @return a map containing the parsed infos
        std::unique_ptr<std::map<std::string, std::string>> parsePropertyInfo(std::string location);

        /// @brief Parse infos from a file (usually /proc/cpuinfo) in a key:value format and categorize them from a category key.
        /// @param location the location of the file to parse
        /// @param categoryKey the key to categorize the infos into submaps (e.g. "processor")
        /// @return a map containing the parsed infos
        std::unique_ptr<std::map<std::string, std::map<std::string, std::string>>> parseCategorizedInfo(std::string location, std::string categoryKey);

        /// @brief Parse a file containing a single integer.
        /// @param location the location of the file to parse
        /// @return the parsed integer
        bool parseBoolFile(std::string location);
    };
};
