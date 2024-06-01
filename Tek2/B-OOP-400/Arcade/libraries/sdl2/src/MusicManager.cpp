/*
** EPITECH PROJECT, 2024
** MusicManager.cpp
** File description:
** MusicManager.cpp
*/

#include "MusicManager.hpp"

namespace sdl2 {
    Music::~Music()
    {
        if (this->_music != nullptr)
            Mix_FreeMusic(this->_music);
    }

    bool Music::load(const arc::MusicSpecification &specification)
    {
        this->_spec = specification;
        this->_music = Mix_LoadMUS(specification.path.c_str());
        return this->_music != nullptr;
    }

    bool MusicManager::load(const std::string &name, const arc::MusicSpecification &specification)
    {
        auto music = std::make_shared<Music>();
        if (!music->load(specification))
            return false;
        this->_musics[name] = music;
        return true;
    }

    std::map<std::string, arc::MusicSpecification> MusicManager::dump() const
    {
        std::map<std::string, arc::MusicSpecification> musics;

        for (auto &music : this->_musics)
            musics[music.first] = music.second->specification();

        return musics;
    }

    void MusicManager::play(const std::string &name, const float volume)
    {
        if (this->_musics.find(name) == this->_musics.end())
            return;

        auto music = this->_musics[name]->music();
        if (music == nullptr)
            return;

        Mix_PlayMusic(music, -1);
        Mix_VolumeMusic(volume / 100.0f * MIX_MAX_VOLUME);
        this->_currentMusic = name;
    }

    void MusicManager::stop(const std::string &name)
    {
        if (!this->_currentMusic.has_value() || this->_currentMusic.value() != name)
            return;

        Mix_HaltMusic();
        this->_currentMusic.reset();
    }

    bool MusicManager::isPlaying(const std::string &name)
    {
        if (!this->_currentMusic.has_value() || this->_currentMusic.value() != name)
            return false;
        return Mix_PlayingMusic() != 0;
    }
}
