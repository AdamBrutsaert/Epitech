/*
** EPITECH PROJECT, 2024
** SoundManager.hpp
** File description:
** SoundManager.hpp
*/

#pragma once

#include "arcade/ISoundManager.hpp"

#include <SDL2/SDL_mixer.h>

#include <memory>

namespace sdl2 {
    class Sound : public arc::ISound {
    public:
        Sound() = default;
        virtual ~Sound() = default;

        bool load(const arc::SoundSpecification& specification);
        virtual const arc::SoundSpecification& specification() const { return this->_spec; }

        Mix_Chunk* sound() const { return this->_sound; }

    private:
        arc::SoundSpecification _spec;
        Mix_Chunk *_sound;
    };

    class SoundManager : public arc::ISoundManager {
    public:
        SoundManager() = default;
        virtual ~SoundManager() = default;

        virtual bool load(const std::string& name, const arc::SoundSpecification& specification);
        virtual std::map<std::string, arc::SoundSpecification> dump() const;

        virtual void play(const std::string& name, const float volume);
        virtual void stop(const std::string& name);

    private:
        std::map<std::string, std::shared_ptr<Sound>> _sounds;
    };
}
