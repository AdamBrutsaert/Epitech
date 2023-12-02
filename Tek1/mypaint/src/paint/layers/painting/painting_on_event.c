/*
** EPITECH PROJECT, 2023
** painting_on_event.c
** File description:
** painting_on_event.c
*/

#include "private/paint/layers/painting.h"

static void switch_tool(painting_t *painting, sfEvent *event)
{
    if (event->key.code == sfKeyP)
        tool_set_type(painting->tool, TOOL_PENCIL);
    if (event->key.code == sfKeyE)
        tool_set_type(painting->tool, TOOL_ERASER);
    if (event->key.code == sfKeyH)
        tool_set_type(painting->tool, TOOL_HAND);
}

bool painting_on_event(context_t *ctx, void *data, sfEvent *event)
{
    painting_t *painting = data;

    if (event->type == sfEvtKeyPressed)
        switch_tool(painting, event);

    return canvas_on_event(ctx, painting->canvas, event)
        && tool_on_event(painting->tool, ctx, event);
}
