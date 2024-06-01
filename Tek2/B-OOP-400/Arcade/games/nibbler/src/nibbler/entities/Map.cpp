/*
** EPITECH PROJECT, 2024
** Map.cpp
** File description:
** Map.cpp
*/

#include "nibbler/entities/Map.hpp"

#include <fstream>
#include <iostream>

namespace nibbler::entities {
    Map::Map()
    {
        

        // Open assets/nibbler/maps/level1.txt
        // # = wall, ' ' = empty
        // Read the file and fill the _tiles vector
        std::ifstream file("assets/nibbler/maps/level1.txt");

        if (!file) {
            std::cerr << "Failed to open assets/nibbler/maps/level1.txt" << std::endl;

            this->_width = 20;
            this->_height = 20;

            this->_tiles.resize(this->_height);
            for (auto& row : this->_tiles)
                row.resize(this->_width, Tile::EMPTY);

            for (uint32_t x = 0; x < this->_width; x++) {
                this->_tiles[0][x] = Tile::WALL;
                this->_tiles[this->_height - 1][x] = Tile::WALL;
            }

            for (uint32_t y = 0; y < this->_height; y++) {
                this->_tiles[y][0] = Tile::WALL;
                this->_tiles[y][this->_width - 1] = Tile::WALL;
            }
        } else {
            std::string line;

            this->_width = 0;
            this->_height = 0;

            while (std::getline(file, line)) {
                this->_tiles.push_back(std::vector<Tile>());

                for (uint32_t x = 0; x < line.size(); x++)
                    this->_tiles[this->_height].push_back(line[x] == '#' ? Tile::WALL : Tile::EMPTY);

                this->_width = std::max(this->_width, static_cast<uint32_t>(line.size()));
                this->_height++;
            }

            // Fill every rows with the same width
            for (auto& row : this->_tiles)
                row.resize(this->_width, Tile::EMPTY);
        }
    }

    void Map::draw(arc::ILibrary& lib)
    {
        for (uint32_t y = 0; y < _tiles.size(); y++) {
            for (uint32_t x = 0; x < _tiles[y].size(); x++) {
                if (_tiles[y][x] == Tile::WALL)
                    lib.display().draw(lib.textures().get("wall"), x, y);
            }
        }
    }
}
