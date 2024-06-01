/*
** EPITECH PROJECT, 2024
** Rect.hpp
** File description:
** Rect.hpp
*/

#pragma once

#include <cstdint>

namespace arc {
    /**
     * @brief Represents a rectangle
     */
    template<typename T>
    struct Rect {
        T x;
        T y;
        T width;
        T height;
    };

    using FRect = Rect<float>;
    using URect = Rect<uint32_t>;
}
