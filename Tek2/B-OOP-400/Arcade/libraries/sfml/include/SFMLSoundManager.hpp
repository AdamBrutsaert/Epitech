/*
** EPITECH PROJECT, 2024
** SFMLMusicManager.hpp
** File description:
** SFMLMusicManager.hpp
*/

#pragma once

#include "arcade/ISoundManager.hpp"

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <map>
#include <memory>

class SFMLSound : public arc::ISound {
public:
    SFMLSound() = default;
    virtual ~SFMLSound() = default;

    bool load(const arc::SoundSpecification& specification);
    virtual const arc::SoundSpecification& specification() const { return this->_spec; }

    void play(const float volume);
    void stop();

private:
    arc::SoundSpecification _spec;
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
};

class SFMLSoundManager : public arc::ISoundManager {
public:
    SFMLSoundManager() = default;
    virtual ~SFMLSoundManager() = default;

    virtual bool load(const std::string& name, const arc::SoundSpecification& specification);
    virtual std::map<std::string, arc::SoundSpecification> dump() const;

    virtual void play(const std::string& name, const float volume);
    virtual void stop(const std::string& name);
private:
    std::map<std::string, std::shared_ptr<SFMLSound>> _musics;
};
