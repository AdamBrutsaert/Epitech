/*
** EPITECH PROJECT, 2024
** Background.hpp
** File description:
** Background.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

#include <vector>

namespace nibbler::entities {
    enum class BackgroundType {
        GRASS,
        HERB_1,
        HERB_2,
        HERB_3,
    };

    class Background {
    public:
        Background(uint32_t width, uint32_t height);
        ~Background() = default;

        void draw(arc::ILibrary& lib);

    private:
        std::vector<std::vector<BackgroundType>> _background;
    };
}
