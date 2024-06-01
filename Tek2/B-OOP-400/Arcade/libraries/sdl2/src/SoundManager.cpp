/*
** EPITECH PROJECT, 2024
** SoundManager.cpp
** File description:
** SoundManager.cpp
*/

#include "SoundManager.hpp"

namespace sdl2 {
    bool Sound::load(const arc::SoundSpecification &specification)
    {
        this->_spec = specification;
        this->_sound = Mix_LoadWAV(specification.path.c_str());
        return this->_sound != nullptr;
    }

    bool SoundManager::load(const std::string &name, const arc::SoundSpecification &specification)
    {
        auto sound = std::make_shared<Sound>();
        sound->load(specification);
        this->_sounds[name] = sound;
        return true;
    }

    std::map<std::string, arc::SoundSpecification> SoundManager::dump() const
    {
        std::map<std::string, arc::SoundSpecification> sounds;

        for (auto &sound : this->_sounds)
            sounds[sound.first] = sound.second->specification();

        return sounds;
    }

    void SoundManager::play(const std::string &name, const float volume)
    {
        auto sound = this->_sounds[name]->sound();
        if (sound == nullptr)
            return;

        Mix_VolumeChunk(sound, volume / 100.0f * MIX_MAX_VOLUME);
        Mix_PlayChannel(-1, sound, 0);
    }

    void SoundManager::stop(const std::string &name)
    {
        (void)name;
    }
}
