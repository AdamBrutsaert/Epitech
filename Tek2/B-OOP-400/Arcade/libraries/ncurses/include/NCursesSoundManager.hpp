/*
** EPITECH PROJECT, 2024
** NCursesSoundManager.hpp
** File description:
** NCursesSoundManager.hpp
*/

#pragma once

#include "arcade/ISoundManager.hpp"

#include <map>
#include <memory>

class NCursesSound : public arc::ISound {
public:
    NCursesSound() = default;
    virtual ~NCursesSound() = default;

    void load(const arc::SoundSpecification& spec) { this->_spec = spec; }
    const arc::SoundSpecification& specification() const { return this->_spec; }

private:
    arc::SoundSpecification _spec;
};

class NCursesSoundManager : public arc::ISoundManager {
public:
    NCursesSoundManager() = default;
    virtual ~NCursesSoundManager() = default;

    virtual bool load(const std::string& name, const arc::SoundSpecification& spec);
    virtual std::map<std::string, arc::SoundSpecification> dump() const;

    virtual void play(const std::string& name, const float volume);
    virtual void stop(const std::string& name);

private:
    std::map<std::string, std::shared_ptr<NCursesSound>> _musics;
};
