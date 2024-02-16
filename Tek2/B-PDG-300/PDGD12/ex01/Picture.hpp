/*
** EPITECH PROJECT, 2024
** Picture.hpp
** File description:
** Picture.hpp
*/

#pragma once

#include <string>

class Picture {
public:
    Picture() = default;
    Picture(const std::string &file);
    Picture(const Picture &picture) = default;
    Picture(Picture &&picture) = default;
    Picture& operator=(const Picture &picture) = default;
    Picture& operator=(Picture &&picture) = default;
    ~Picture() = default;

    bool getPictureFromFile(const std::string &file);

public:
    std::string data;
};
