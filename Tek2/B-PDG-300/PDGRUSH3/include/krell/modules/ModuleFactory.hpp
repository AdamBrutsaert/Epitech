/*
** EPITECH PROJECT, 2024
** ModuleFactory.hpp
** File description:
** ModuleFactory.hpp
*/

#pragma once

#include "IModule.hpp"
#include <map>
#include <functional>

namespace Krell {
    class ModuleFactory {
    public:
        ModuleFactory();
        ~ModuleFactory() = default;

        bool hasModule(const std::string &name) const { return _modules.count(name); };
        std::unique_ptr<Krell::IModule> createModule(const std::string &name);
    private:
        std::map<std::string, std::function<std::unique_ptr<Krell::IModule>()>> _modules;
    private:
        std::unique_ptr<Krell::IModule> createSystemInfoModule();
        std::unique_ptr<Krell::IModule> createCpuInfoModule();
        std::unique_ptr<Krell::IModule> createRamInfoModule();
        std::unique_ptr<Krell::IModule> createBatteryInfoModule();
    };
};
