/*
** EPITECH PROJECT, 2023
** canvas_clear.c
** File description:
** canvas_clear.c
*/

#include "private/paint/components/canvas.h"

void canvas_clear(canvas_t *canvas)
{
    sfRenderTexture_clear(canvas->texture, sfWhite);
}
