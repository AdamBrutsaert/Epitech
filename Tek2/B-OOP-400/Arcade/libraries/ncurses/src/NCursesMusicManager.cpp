/*
** EPITECH PROJECT, 2024
** NCursesMusicManager.cpp
** File description:
** NCursesMusicManager.cpp
*/

#include "NCursesMusicManager.hpp"

bool NCursesMusicManager::load(const std::string& name, const arc::MusicSpecification& spec)
{
    auto music = std::make_shared<NCursesMusic>();
    music->load(spec);
    this->_musics[name] = music;
    return true;
}

std::map<std::string, arc::MusicSpecification> NCursesMusicManager::dump() const
{
    auto specs = std::map<std::string, arc::MusicSpecification>{};

    for (const auto& [name, music] : this->_musics)
        specs[name] = music->specification();

    return specs;
}

void NCursesMusicManager::play([[maybe_unused]] const std::string& name, [[maybe_unused]] const float volume)
{
}

void NCursesMusicManager::stop([[maybe_unused]] const std::string& name)
{
}

bool NCursesMusicManager::isPlaying([[maybe_unused]] const std::string& name)
{
    return false;
}
