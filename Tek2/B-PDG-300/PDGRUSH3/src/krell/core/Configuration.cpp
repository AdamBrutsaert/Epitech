/*
** EPITECH PROJECT, 2024
** Configuration.cpp
** File description:
** Configuration.cpp
*/

#include "krell/core/Configuration.hpp"
#include "krell/modules/ModuleFactory.hpp"
#include <argp.h>
#include <fstream>
#include <iostream>

const char *argp_program_version = "Krell v1.69.1";
const char *argp_program_bug_address = "contact@lesquatrepoggers.fr";
char doc[] = {
    "A better top!\nPress <Tab> to select the next module\nPress <D> to delete the selected module\nPress <Arrow Up> to move the selected module up\nPress <Arrow Down> to move the selected module down\nPress <S> to append a System Info module\nPress <C> to append a CPU Info module\nPress <R> to append a RAM Info module"
};
struct argp_option options[] = {
    { "config", 'c', "config.krell", 0, "File to read configuration from" },
    { "display", 'd', "ncurses", 0, "Display mode (ncurses, sfml)" },
    { 0 }
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    Krell::Configuration *config = (Krell::Configuration *) state->input;

    switch (key) {
    case 'c':
        config->configFile = arg;
        break;
    case 'd':
        config->displayMode = Krell::getDisplayModeFromString(arg);
        if (config->displayMode == Krell::DisplayMode::UNKNOWN)
            return ARGP_ERR_UNKNOWN;
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
} 

static struct argp argp = { options, parse_opt, 0, doc, 0, 0, 0 };

void Krell::Parser::parseFlags(int argc, char **argv, Configuration &config)
{
    argp_parse(&argp, argc, argv, 0, 0, &config);
}

bool Krell::Parser::parseFile(Configuration &config)
{
    std::ifstream file(config.configFile);
    std::string line;

    Krell::ModuleFactory factory;

    if (!file.is_open() || !file.good())
        return false; // TODO: Basic config if file not found
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;
        if (!factory.hasModule(line)) {
            std::cerr << "Unknown module: " << line << std::endl;
            continue;
        }
        auto module = factory.createModule(line);
        config.modules.push_back(std::move(module));
    }
    return true;
}   
