/*
** EPITECH PROJECT, 2023
** eraser_destroy.c
** File description:
** eraser_destroy.c
*/

#include "private/paint/components/tools/eraser.h"
#include "my/memory.h"

void eraser_destroy(eraser_t *eraser)
{
    if (!eraser)
        return;
    sfRectangleShape_destroy(eraser->rect);
    sfCircleShape_destroy(eraser->shape);
    my_free(eraser);
}
