/*
** EPITECH PROJECT, 2024
** ILibrary.hpp
** File description:
** ILibrary.hpp
*/

#pragma once

#include "IDisplay.hpp"
#include "ISoundManager.hpp"
#include "IMusicManager.hpp"

namespace arc {

    /**
     * @brief Represents a library that is exported by a shared library.
     */
    class ILibrary {
    public:
        virtual ~ILibrary() = default;

        /**
         * @brief Returns the display of the library
         *
         * @return IDisplay& The display
         */
        virtual IDisplay& display() = 0;

        /**
         * @brief Returns the texture manager of the library
         *
         * @return ITextureManager& The texture manager
         */
        virtual ITextureManager& textures() = 0;

        /**
         * @brief Returns the font manager of the library
         *
         * @return IFontManager& The font manager
         */
        virtual IFontManager& fonts() = 0;

        /**
         * @brief Returns the sound manager of the library
         *
         * @return ISoundManager& The sound manager
         */
        virtual ISoundManager& sounds() = 0;

        /**
         * @brief Returns the music manager of the library
         *
         * @return IMusicManager& The music manager
         */
        virtual IMusicManager& musics() = 0;
    };
};
