/*
** EPITECH PROJECT, 2024
** ModuleFactory.cpp
** File description:
** ModuleFactory.cpp
*/

#include "krell/modules/ModuleFactory.hpp"
#include "krell/modules/SystemInfoModule.hpp"
#include "krell/modules/CpuModule.hpp"
#include "krell/modules/RamModule.hpp"
#include "krell/modules/BatteryModule.hpp"

Krell::ModuleFactory::ModuleFactory()
{
    _modules["systemInfo"] = std::bind(&Krell::ModuleFactory::createSystemInfoModule, this);
    _modules["cpuInfo"] = std::bind(&Krell::ModuleFactory::createCpuInfoModule, this);
    _modules["ramInfo"] = std::bind(&Krell::ModuleFactory::createRamInfoModule, this);
    _modules["batteryInfo"] = std::bind(&Krell::ModuleFactory::createBatteryInfoModule, this);
}

std::unique_ptr<Krell::IModule> Krell::ModuleFactory::createModule(const std::string &name)
{
    if (!this->_modules[name])
        throw std::runtime_error("Module " + name + " not found");
    return this->_modules[name]();
}

std::unique_ptr<Krell::IModule> Krell::ModuleFactory::createSystemInfoModule()
{
    return std::move(std::make_unique<Krell::SystemInfoModule>());
}

std::unique_ptr<Krell::IModule>  Krell::ModuleFactory::createCpuInfoModule()
{
    return std::move(std::make_unique<Krell::CpuModule>());
}

std::unique_ptr<Krell::IModule>  Krell::ModuleFactory::createRamInfoModule()
{
    return std::move(std::make_unique<Krell::RamModule>());
}

std::unique_ptr<Krell::IModule>  Krell::ModuleFactory::createBatteryInfoModule()
{
    return std::move(std::make_unique<Krell::BatteryModule>());
}
