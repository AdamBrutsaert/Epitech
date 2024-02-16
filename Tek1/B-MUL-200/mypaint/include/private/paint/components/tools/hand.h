/*
** EPITECH PROJECT, 2023
** hand.h
** File description:
** hand.h
*/

#pragma once

#include "paint/components/tools/hand.h"

struct hand {
    canvas_t *canvas;
    sfVector2i last_position;
    bool is_pressing;
};
