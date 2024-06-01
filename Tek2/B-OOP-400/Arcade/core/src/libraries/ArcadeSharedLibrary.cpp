/*
** EPITECH PROJECT, 2024
** ArcadeSharedLibrary.cpp
** File description:
** ArcadeSharedLibrary.cpp
*/

#include "libraries/ArcadeSharedLibrary.hpp"

namespace core {
    std::optional<ArcadeLibraryDump> ArcadeSharedLibrary<arc::ILibrary>::dump() const
    {
        if (this->instance() == nullptr)
            return std::nullopt;

        return ArcadeLibraryDump{
            .title = this->instance()->display().title(),
            .framerate = this->instance()->display().framerate(),
            .tileSize = this->instance()->display().tileSize(),
            .width = this->instance()->display().width(),
            .height = this->instance()->display().height(),
            .textures = this->instance()->textures().dump(),
            .fonts = this->instance()->fonts().dump(),
            .sounds = this->instance()->sounds().dump(),
            .musics = this->instance()->musics().dump()
        };
    }

    void ArcadeSharedLibrary<arc::ILibrary>::restore(const std::optional<ArcadeLibraryDump>& dumped)
    {
        if (this->instance() == nullptr || !dumped.has_value())
            return;

        this->instance()->display().setTitle(dumped->title);
        this->instance()->display().setFramerate(dumped->framerate);
        this->instance()->display().setTileSize(dumped->tileSize);
        this->instance()->display().setWidth(dumped->width);
        this->instance()->display().setHeight(dumped->height);

        for (const auto& [name, texture] : dumped->textures)
            this->instance()->textures().load(name, texture);
        for (const auto& [name, font] : dumped->fonts)
            this->instance()->fonts().load(name, font);
        for (const auto& [name, sound] : dumped->sounds)
            this->instance()->sounds().load(name, sound);
        for (const auto& [name, music] : dumped->musics)
            this->instance()->musics().load(name, music);
    }
}
