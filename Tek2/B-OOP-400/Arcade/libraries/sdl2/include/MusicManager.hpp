/*
** EPITECH PROJECT, 2024
** MusicManager.hpp
** File description:
** MusicManager.hpp
*/

#pragma once

#include "arcade/IMusicManager.hpp"

#include <SDL2/SDL_mixer.h>

#include <memory>
#include <optional>

namespace sdl2 {
    class Music : public arc::IMusic {
    public:
        Music() = default;
        virtual ~Music();

        bool load(const arc::MusicSpecification& specification);
        virtual const arc::MusicSpecification& specification() const { return this->_spec; }

        Mix_Music* music() const { return this->_music; }

    private:
        arc::MusicSpecification _spec;
        Mix_Music *_music;
    };

    class MusicManager : public arc::IMusicManager {
    public:
        MusicManager() = default;
        virtual ~MusicManager() = default;

        virtual bool load(const std::string& name, const arc::MusicSpecification& specification);
        virtual std::map<std::string, arc::MusicSpecification> dump() const;

        virtual void play(const std::string& name, const float volume);
        virtual void stop(const std::string& name);
        virtual bool isPlaying(const std::string& name);

    private:
        std::map<std::string, std::shared_ptr<Music>> _musics;
        std::optional<std::string> _currentMusic;
    };
}
