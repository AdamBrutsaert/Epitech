/*
** EPITECH PROJECT, 2024
** NCursesMusicManager.hpp
** File description:
** NCursesMusicManager.hpp
*/

#pragma once

#include "arcade/IMusicManager.hpp"

#include <map>
#include <memory>

class NCursesMusic : public arc::IMusic {
public:
    NCursesMusic() = default;
    virtual ~NCursesMusic() = default;

    void load(const arc::MusicSpecification& spec) { this->_spec = spec; }
    const arc::MusicSpecification& specification() const { return this->_spec; }

private:
    arc::MusicSpecification _spec;
};

class NCursesMusicManager : public arc::IMusicManager {
public:
    NCursesMusicManager() = default;
    virtual ~NCursesMusicManager() = default;

    virtual bool load(const std::string& name, const arc::MusicSpecification& spec);
    virtual std::map<std::string, arc::MusicSpecification> dump() const;

    virtual void play(const std::string& name, const float volume);
    virtual void stop(const std::string& name);
    virtual bool isPlaying(const std::string& name);

private:
    std::map<std::string, std::shared_ptr<NCursesMusic>> _musics;
};
