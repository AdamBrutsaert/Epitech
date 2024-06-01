/*
** EPITECH PROJECT, 2024
** SFMLMusicManager.hpp
** File description:
** SFMLMusicManager.hpp
*/

#pragma once

#include "arcade/IMusicManager.hpp"

#include <SFML/Audio/Music.hpp>

#include <map>
#include <memory>

class SFMLMusic : public arc::IMusic {
public:
    SFMLMusic() = default;
    virtual ~SFMLMusic() = default;

    bool load(const arc::MusicSpecification& specification);
    virtual const arc::MusicSpecification& specification() const { return this->_spec; }

    void play(const float volume);
    void stop();
    bool isPlaying() const;

private:
    arc::MusicSpecification _spec;
    sf::Music _music;
};

class SFMLMusicManager : public arc::IMusicManager {
public:
    SFMLMusicManager() = default;
    virtual ~SFMLMusicManager() = default;

    virtual bool load(const std::string& name, const arc::MusicSpecification& specification);
    virtual std::map<std::string, arc::MusicSpecification> dump() const;

    virtual void play(const std::string& name, const float volume);
    virtual void stop(const std::string& name);
    virtual bool isPlaying(const std::string& name);
private:
    std::map<std::string, std::shared_ptr<SFMLMusic>> _musics;
};
