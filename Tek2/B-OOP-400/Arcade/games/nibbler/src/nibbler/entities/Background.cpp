/*
** EPITECH PROJECT, 2024
** Background.cpp
** File description:
** Background.cpp
*/

#include "nibbler/entities/Background.hpp"

namespace nibbler::entities {
    Background::Background(uint32_t width, uint32_t height)
    {
        for (size_t i = 0; i < height; i++) {
            std::vector<BackgroundType> line;

            for (size_t j = 0; j < width; j++) {
                auto n = rand() % 6;
                if (n == 0) line.push_back(BackgroundType::HERB_1);
                else if (n == 1) line.push_back(BackgroundType::HERB_2);
                else if (n == 2) line.push_back(BackgroundType::HERB_3);
                else line.push_back(BackgroundType::GRASS);
            }

            this->_background.push_back(std::move(line));
        }
    }

    void Background::draw(arc::ILibrary& lib)
    {
        for (size_t i = 0; i < lib.display().height(); i++) {
            for (size_t j = 0; j < lib.display().width(); j++) {
                switch (this->_background[i][j]) {
                case BackgroundType::GRASS:
                    lib.display().draw(lib.textures().get("grass"), j, i);
                    break;
                case BackgroundType::HERB_1:
                    lib.display().draw(lib.textures().get("herb1"), j, i);
                    break;
                case BackgroundType::HERB_2:
                    lib.display().draw(lib.textures().get("herb2"), j, i);
                    break;
                case BackgroundType::HERB_3:
                    lib.display().draw(lib.textures().get("herb3"), j, i);
                    break;
                }
            }
        }
    }
}
