/*
** EPITECH PROJECT, 2024
** SFMLMusicManager.cpp
** File description:
** SFMLMusicManager.cpp
*/

#include "SFMLMusicManager.hpp"

bool SFMLMusic::load(const arc::MusicSpecification& specification)
{
    this->_spec = specification;
    if (!this->_music.openFromFile(specification.path))
        return false;
    this->_music.setLoop(specification.loop);
    this->_music.setPlayingOffset(sf::seconds(specification.startOffset));
    return true;
}

void SFMLMusic::play(const float volume)
{
    this->_music.setVolume(volume);
    this->_music.play();
}

void SFMLMusic::stop()
{
    this->_music.stop();
}

bool SFMLMusic::isPlaying() const
{
    return this->_music.getStatus() == sf::Music::Playing;
}

bool SFMLMusicManager::load(const std::string& name, const arc::MusicSpecification& specification)
{
    auto music = std::make_shared<SFMLMusic>();
    if (!music->load(specification))
        return false;
    this->_musics[name] = music;
    return true;
}

std::map<std::string, arc::MusicSpecification> SFMLMusicManager::dump() const
{
    std::map<std::string, arc::MusicSpecification> res;

    for (auto& [name, music] : this->_musics)
        res[name] = music->specification();

    return res;
}

void SFMLMusicManager::play(const std::string& name, const float volume)
{
    if (this->_musics.find(name) == this->_musics.end())
        return;
    this->_musics[name]->play(volume);
}

void SFMLMusicManager::stop(const std::string& name)
{
    if (this->_musics.find(name) == this->_musics.end())
        return;
    this->_musics[name]->stop();
}

bool SFMLMusicManager::isPlaying(const std::string& name)
{
    if (this->_musics.find(name) == this->_musics.end())
        return false;
    return this->_musics[name]->isPlaying();
}
