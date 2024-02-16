/*
** EPITECH PROJECT, 2023
** toolbox_on_render.c
** File description:
** toolbox_on_render.c
*/

#include "private/paint/layers/toolbox.h"

bool toolbox_on_render(context_t *ctx, void *data)
{
    toolbox_t *toolbox = data;
    bool status;

    if (toolbox->tool && tool_get_type(toolbox->tool) != TOOL_HAND) {
        status = button_on_render(ctx, toolbox->grow)
            && button_on_render(ctx, toolbox->shrink)
            && button_on_render(ctx, toolbox->circle)
            && button_on_render(ctx, toolbox->rect);
        sfRenderWindow_drawRectangleShape(context_get_window(ctx),
            toolbox->rect_shape, NULL);
        sfRenderWindow_drawCircleShape(context_get_window(ctx),
            toolbox->circle_shape, NULL);
        return status;
    }
    return true;
}
