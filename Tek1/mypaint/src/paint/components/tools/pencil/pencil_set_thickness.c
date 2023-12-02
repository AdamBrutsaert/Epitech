/*
** EPITECH PROJECT, 2023
** pencil_set_thickness.c
** File description:
** pencil_set_thickness.c
*/

#include "private/paint/components/tools/pencil.h"

void pencil_set_thickness(pencil_t *pencil, float size)
{
    sfCircleShape_setRadius(pencil->shape, size);
    sfRectangleShape_setSize(pencil->rect, (sfVector2f){size * 2, size * 2});
}
