/*
** EPITECH PROJECT, 2023
** canvas_on_render.c
** File description:
** canvas_on_render.c
*/

#include "private/paint/components/canvas.h"

bool canvas_on_render(context_t *ctx, canvas_t *canvas)
{
    sfRenderWindow *window = context_get_window(ctx);
    sfRenderStates states = {sfBlendNone, sfTransform_Identity,
        canvas->bg_texture, NULL };

    sfRenderTexture_display(canvas->texture);
    sfRenderWindow_setView(window, canvas->view);
    sfRenderWindow_drawVertexArray(window, canvas->bg, &states);
    sfRenderWindow_drawSprite(window, canvas->sprite, NULL);
    context_reset_view(ctx);
    return true;
}
