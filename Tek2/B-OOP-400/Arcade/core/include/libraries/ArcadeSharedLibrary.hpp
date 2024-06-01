/*
** EPITECH PROJECT, 2024
** ArcadeSharedLibrary.hpp
** File description:
** ArcadeSharedLibrary.hpp
*/

#pragma once

#include "SharedLibrary.hpp"
#include "arcade/SharedLibraryType.hpp"
#include "arcade/ILibrary.hpp"

#include <memory>

namespace core {
    struct ArcadeLibraryDump {
        // Display
        std::string title;
        uint32_t framerate;
        std::size_t tileSize;
        std::size_t width;
        std::size_t height;

        // Managers
        std::map<std::string, arc::TextureSpecification> textures;
        std::map<std::string, arc::FontSpecification> fonts;
        std::map<std::string, arc::SoundSpecification> sounds;
        std::map<std::string, arc::MusicSpecification> musics;
    };

    struct ArcadeSharedLibrarySpecification {
        std::string path;
        arc::SharedLibraryType type;
        std::string name;
    };

    template<typename T>
    class ArcadeSharedLibraryBase : public SharedLibrary {
    public:
        using SharedLibrary::SharedLibrary;

        virtual bool close() override
        {
            this->_instance.reset();
            return SharedLibrary::close();
        }

        arc::SharedLibraryType type() const
        {
            return this->get<arc::SharedLibraryType>("type", arc::SharedLibraryType::UNKNOWN);
        }

        std::string name() const
        {
            return std::string(this->get<const char*>("name", "Unknown"));
        }

        std::shared_ptr<T> instance() const
        {
            if (this->_instance == nullptr)
                this->_instance = std::shared_ptr<T>(this->get<T*>("entrypoint", nullptr));

            return this->_instance;
        }

        ArcadeSharedLibrarySpecification specification() const
        {
            return {
                this->path(),
                this->type(),
                this->name()
            };
        }

    private:
        mutable std::shared_ptr<T> _instance;
    };

    template<typename T>
    class ArcadeSharedLibrary : public ArcadeSharedLibraryBase<T> {
    public:
        using ArcadeSharedLibraryBase<T>::ArcadeSharedLibraryBase;
    };

    template<>
    class ArcadeSharedLibrary<arc::ILibrary> : public ArcadeSharedLibraryBase<arc::ILibrary>  {
    public:
        using ArcadeSharedLibraryBase<arc::ILibrary>::ArcadeSharedLibraryBase;

        std::optional<ArcadeLibraryDump> dump() const;
        void restore(const std::optional<ArcadeLibraryDump>& dumped);
    };
}
