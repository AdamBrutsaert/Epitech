/*
** EPITECH PROJECT, 2024
** SFMLSoundManager.cpp
** File description:
** SFMLSoundManager.cpp
*/

#include "SFMLSoundManager.hpp"

bool SFMLSound::load(const arc::SoundSpecification& specification)
{
    this->_spec = specification;
    if (!this->_buffer.loadFromFile(specification.path))
        return false;
    this->_sound.setBuffer(this->_buffer);
    return true;
}

void SFMLSound::play(const float volume)
{
    this->_sound.setVolume(volume);
    this->_sound.play();
}

void SFMLSound::stop()
{
    this->_sound.stop();
}

bool SFMLSoundManager::load(const std::string& name, const arc::SoundSpecification& specification)
{
    auto sound = std::make_shared<SFMLSound>();
    if (!sound->load(specification))
        return false;
    this->_musics[name] = sound;
    return true;
}

std::map<std::string, arc::SoundSpecification> SFMLSoundManager::dump() const
{
    std::map<std::string, arc::SoundSpecification> res;

    for (auto& [name, sound] : this->_musics)
        res[name] = sound->specification();

    return res;
}

void SFMLSoundManager::play(const std::string& name, const float volume)
{
    if (this->_musics.find(name) == this->_musics.end())
        return;
    this->_musics[name]->play(volume);
}

void SFMLSoundManager::stop(const std::string& name)
{
    if (this->_musics.find(name) == this->_musics.end())
        return;
    this->_musics[name]->stop();
}
