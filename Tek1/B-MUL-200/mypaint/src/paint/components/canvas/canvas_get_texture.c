/*
** EPITECH PROJECT, 2023
** canvas_get_texture.c
** File description:
** canvas_get_texture.c
*/

#include "private/paint/components/canvas.h"

sfRenderTexture *canvas_get_texture(canvas_t *canvas)
{
    return canvas->texture;
}
