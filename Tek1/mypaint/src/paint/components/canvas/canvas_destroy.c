/*
** EPITECH PROJECT, 2023
** canvas_destroy.c
** File description:
** canvas_destroy.c
*/

#include "private/paint/components/canvas.h"
#include "my/memory.h"

void canvas_destroy(canvas_t *canvas)
{
    if (!canvas)
        return;
    sfTexture_destroy(canvas->bg_texture);
    sfVertexArray_destroy(canvas->bg);
    sfRenderTexture_destroy(canvas->texture);
    sfSprite_destroy(canvas->sprite);
    sfView_destroy(canvas->view);
    my_free(canvas);
}
