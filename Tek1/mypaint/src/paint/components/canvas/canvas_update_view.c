/*
** EPITECH PROJECT, 2023
** canvas_update_view.c
** File description:
** canvas_update_view.c
*/

#include "private/paint/components/canvas.h"

void canvas_update_view(canvas_t *canvas, context_t *ctx)
{
    sfVector2u size = sfRenderWindow_getSize(context_get_window(ctx));

    sfView_setCenter(canvas->view, canvas->center);
    sfView_setSize(canvas->view, (sfVector2f){size.x / canvas->zoom,
        size.y / canvas->zoom});
}
