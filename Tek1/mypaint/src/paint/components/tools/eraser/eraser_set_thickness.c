/*
** EPITECH PROJECT, 2023
** eraser_set_thickness.c
** File description:
** eraser_set_thickness.c
*/

#include "private/paint/components/tools/eraser.h"

void eraser_set_thickness(eraser_t *eraser, float size)
{
    sfCircleShape_setRadius(eraser->shape, size);
    sfRectangleShape_setSize(eraser->rect, (sfVector2f){size * 2, size * 2});
}
