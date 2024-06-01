/*
** EPITECH PROJECT, 2024
** NCursesSoundManager.cpp
** File description:
** NCursesSoundManager.cpp
*/

#include "NCursesSoundManager.hpp"

bool NCursesSoundManager::load(const std::string& name, const arc::SoundSpecification& spec)
{
    auto music = std::make_shared<NCursesSound>();
    music->load(spec);
    this->_musics[name] = music;
    return true;
}

std::map<std::string, arc::SoundSpecification> NCursesSoundManager::dump() const
{
    auto specs = std::map<std::string, arc::SoundSpecification>{};

    for (const auto& [name, music] : this->_musics)
        specs[name] = music->specification();

    return specs;
}

void NCursesSoundManager::play([[maybe_unused]] const std::string& name, [[maybe_unused]] const float volume)
{
}

void NCursesSoundManager::stop([[maybe_unused]] const std::string& name)
{
}
