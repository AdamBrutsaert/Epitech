/*
** EPITECH PROJECT, 2023
** pencil_destroy.c
** File description:
** pencil_destroy.c
*/

#include "private/paint/components/tools/pencil.h"
#include "my/memory.h"

void pencil_destroy(pencil_t *pencil)
{
    if (!pencil)
        return;
    sfCircleShape_destroy(pencil->shape);
    sfRectangleShape_destroy(pencil->rect);
    my_free(pencil);
}
