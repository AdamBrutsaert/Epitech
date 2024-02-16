/*
** EPITECH PROJECT, 2023
** canvas_on_event.c
** File description:
** canvas_on_event.c
*/

#include "private/paint/components/canvas.h"

bool canvas_on_event(__attribute__((unused)) context_t *ctx, canvas_t *canvas,
    sfEvent *event)
{
    if (event->type == sfEvtMouseWheelScrolled)
        canvas_zoom(canvas, event->mouseWheelScroll.delta);
    if (event->type == sfEvtResized)
        canvas_update_view(canvas, ctx);
    return true;
}
