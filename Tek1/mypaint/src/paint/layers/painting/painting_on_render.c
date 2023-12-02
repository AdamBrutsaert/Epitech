/*
** EPITECH PROJECT, 2023
** painting_on_render.c
** File description:
** painting_on_render.c
*/

#include "private/paint/layers/painting.h"

bool painting_on_render(context_t *ctx, void *data)
{
    painting_t *painting = data;

    sfRenderWindow_clear(context_get_window(ctx), sfColor_fromRGB(48, 48, 48));
    return canvas_on_render(ctx, painting->canvas);
}
