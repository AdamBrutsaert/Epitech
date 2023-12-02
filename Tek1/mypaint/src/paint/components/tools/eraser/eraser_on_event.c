/*
** EPITECH PROJECT, 2023
** eraser_on_event.c
** File description:
** eraser_on_event.c
*/

#include "private/paint/components/tools/eraser.h"

bool eraser_on_event(context_t *ctx, eraser_t *eraser, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed) {
        eraser->is_pressing = true;
        eraser->last_position = sfRenderWindow_mapPixelToCoords(
            context_get_window(ctx),
            (sfVector2i){event->mouseButton.x, event->mouseButton.y},
            canvas_get_view(eraser->canvas)
        );
    }
    if (event->type == sfEvtMouseButtonReleased)
        eraser->is_pressing = false;
    return true;
}
