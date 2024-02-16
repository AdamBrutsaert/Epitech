/*
** EPITECH PROJECT, 2023
** eraser.h
** File description:
** eraser.h
*/

#pragma once

#include "paint/components/tools/eraser.h"

struct eraser {
    canvas_t *canvas;
    sfCircleShape *shape;
    sfRectangleShape *rect;
    sfVector2f last_position;
    bool is_pressing;
    bool is_rect;
};
