/*
** EPITECH PROJECT, 2023
** pencil.h
** File description:
** pencil.h
*/

#pragma once

#include "paint/components/tools/pencil.h"

struct pencil {
    canvas_t *canvas;
    sfCircleShape *shape;
    sfRectangleShape *rect;
    sfVector2f last_position;
    bool is_pressing;
    bool is_rect;
};
