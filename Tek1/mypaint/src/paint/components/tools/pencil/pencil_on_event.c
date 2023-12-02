/*
** EPITECH PROJECT, 2023
** pencil_on_event.c
** File description:
** pencil_on_event.c
*/

#include "private/paint/components/tools/pencil.h"

bool pencil_on_event(context_t *ctx, pencil_t *pencil, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed) {
        pencil->is_pressing = true;
        pencil->last_position = sfRenderWindow_mapPixelToCoords(
            context_get_window(ctx),
            (sfVector2i){event->mouseButton.x, event->mouseButton.y},
            canvas_get_view(pencil->canvas)
        );
    }
    if (event->type == sfEvtMouseButtonReleased)
        pencil->is_pressing = false;
    return true;
}
